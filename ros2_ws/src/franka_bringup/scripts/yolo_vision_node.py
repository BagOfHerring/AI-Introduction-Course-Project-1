#!/usr/bin/env python3
"""
YOLO Vision Detection Node
===========================
Subscribes to the MuJoCo overhead camera, runs YOLOv8 object detection,
draws bounding boxes on the image, and publishes part type/size/world
coordinates to the pick-and-place pipeline.

This node expects a YOLOv8 model trained on four classes:
    - gear
    - square_gear
    - nut
    - bearing
"""
from pathlib import Path
from typing import Optional

import numpy as np
import cv2

import rclpy
from rclpy.node import Node
from rcl_interfaces.msg import ParameterDescriptor
from cv_bridge import CvBridge

from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import Float32, String


# ── Color palette for bounding boxes (BGR) ──────────────────────────────────
CLASS_COLORS = {
    'gear':        (0, 200, 200),   # yellow
    'square_gear': (0, 200, 0),     # green
    'nut':         (0, 140, 255),   # orange
    'bearing':     (255, 160, 50),  # light blue
    'unknown':     (180, 180, 180), # gray
}


CLASS_ALIASES = {
    'gear': 'gear',
    'round_gear': 'gear',
    'circular_gear': 'gear',
    'circle_gear': 'gear',
    '圆齿齿轮': 'gear',
    '圆齿轮': 'gear',
    'square_gear': 'square_gear',
    'squaregear': 'square_gear',
    '方齿齿轮': 'square_gear',
    '方齿轮': 'square_gear',
    'nut': 'nut',
    '螺母': 'nut',
    'bearing': 'bearing',
    '轴承': 'bearing',
}

SUPPORTED_CLASSES = ('gear', 'square_gear', 'nut', 'bearing')


def canonicalize_class_name(class_name: str) -> Optional[str]:
    normalized = class_name.strip().lower().replace('-', '_').replace(' ', '_')
    return CLASS_ALIASES.get(normalized)


def resolve_model_path(model_path: str) -> str:
    raw_path = Path(model_path).expanduser()
    if raw_path.is_file():
        return str(raw_path)

    script_dir = Path(__file__).resolve().parent
    candidates = [
        Path.cwd() / model_path,
        script_dir / model_path,
        script_dir / 'weights' / model_path,
    ]
    for candidate in candidates:
        if candidate.is_file():
            return str(candidate)

    return model_path


def normalize_device_parameter(value) -> str:
    if value is None:
        return ''
    if isinstance(value, str):
        return value.strip()
    return str(value)


def iter_model_class_names(model) -> list[str]:
    names = getattr(model, 'names', {})
    if isinstance(names, dict):
        return [str(name) for name in names.values()]
    if isinstance(names, (list, tuple)):
        return [str(name) for name in names]
    return []


def get_supported_model_classes(model) -> set[str]:
    supported = set()
    for class_name in iter_model_class_names(model):
        canonical_class = canonicalize_class_name(class_name)
        if canonical_class is not None:
            supported.add(canonical_class)
    return supported


def detect_objects(
    cv_image: np.ndarray,
    model,
    confidence_threshold: float,
    iou_threshold: float,
    input_size: int,
    device: str,
) -> list:
    """
    Run YOLOv8 object detection on a single BGR image.

    Returns a list of detections, each being a dict:
        {
            'class':      str,          # e.g. 'gear', 'nut', 'bearing', ...
            'confidence': float,        # 0‥1
            'bbox':       (x1, y1, x2, y2),  # pixel coordinates, top-left & bottom-right
            'size_m':     float,        # estimated real-world diameter / width in meters
        }
    """
    if model is None:
        return []

    predict_kwargs = {
        'source': cv_image,
        'conf': confidence_threshold,
        'iou': iou_threshold,
        'imgsz': input_size,
        'verbose': False,
    }
    if device:
        predict_kwargs['device'] = device

    results = model.predict(**predict_kwargs)
    detections = []

    for result in results:
        boxes = getattr(result, 'boxes', None)
        if boxes is None:
            continue

        names = getattr(result, 'names', {})
        for box in boxes:
            cls_id = int(box.cls[0].item())
            raw_class_name = names.get(cls_id, str(cls_id)) if isinstance(names, dict) else str(cls_id)
            canonical_class = canonicalize_class_name(raw_class_name)
            if canonical_class is None:
                continue

            x1, y1, x2, y2 = [int(round(v)) for v in box.xyxy[0].tolist()]
            x1 = max(0, x1)
            y1 = max(0, y1)
            x2 = max(x1 + 1, x2)
            y2 = max(y1 + 1, y2)

            detections.append({
                'class': canonical_class,
                'confidence': float(box.conf[0].item()),
                'bbox': (x1, y1, x2, y2),
                'size_m': 0.0,
            })

    detections.sort(key=lambda det: det['confidence'], reverse=True)
    return detections


class YoloVisionNode(Node):
    def __init__(self):
        super().__init__('yolo_vision_node')

        self.bridge = CvBridge()

        # ── Camera intrinsics (filled by CameraInfo callback) ───────────
        self.fx = None
        self.fy = None
        self.cx = None
        self.cy = None
        self.cam_pos = np.array([0.5, 0.0, 3.0])   # default, overridden by CameraInfo
        self.table_z = 0.4   # known table‐surface height in world frame

        # ── YOLO model parameters ───────────────────────────────────
        self.declare_parameter('model_path', 'yolov8s.pt')
        self.declare_parameter('confidence_threshold', 0.5)
        self.declare_parameter('iou_threshold', 0.45)
        self.declare_parameter('input_size', 640)
        self.declare_parameter(
            'device',
            '',
            descriptor=ParameterDescriptor(dynamic_typing=True),
        )
        self.declare_parameter('show_debug_window', False)

        self.model_path = self.get_parameter('model_path').value
        self.confidence_threshold = float(self.get_parameter('confidence_threshold').value)
        self.iou_threshold = float(self.get_parameter('iou_threshold').value)
        self.input_size = int(self.get_parameter('input_size').value)
        self.device = normalize_device_parameter(self.get_parameter('device').value)
        self.show_debug_window = bool(self.get_parameter('show_debug_window').value)
        self.model = self._load_model()
        self.model_supported_classes = get_supported_model_classes(self.model)

        # ── Subscribers ─────────────────────────────────────────────────
        self.image_sub = self.create_subscription(
            Image,
            '/mujoco_server/cameras/vision_cam/rgb/image_raw',
            self.image_callback,
            10,
        )
        self.info_sub = self.create_subscription(
            CameraInfo,
            '/mujoco_server/cameras/vision_cam/rgb/camera_info',
            self.camera_info_callback,
            10,
        )

        # ── Publishers ──────────────────────────────────────────────────
        self.pose_pub = self.create_publisher(PoseStamped, '/vision_detector/part_pose', 10)
        self.size_pub = self.create_publisher(Float32, '/vision_detector/part_size', 10)
        self.type_pub = self.create_publisher(String, '/vision_detector/part_type', 10)
        self.annotated_pub = self.create_publisher(Image, '/vision_detector/annotated_image', 10)

        # ── Throttle: only process 1 frame per this many seconds ────────
        self.declare_parameter('process_interval', 0.5)
        self.process_interval = self.get_parameter('process_interval').value
        self.last_process_time = self.get_clock().now()

        self.get_logger().info('YOLO Vision Node started. Waiting for camera feed...')
        self.get_logger().info(
            '  Detecting supported classes: gear, square_gear, nut, bearing'
        )
        if self.model is not None and not self.model_supported_classes:
            raw_classes = iter_model_class_names(self.model)
            preview = ', '.join(raw_classes[:8]) if raw_classes else 'unknown'
            self.get_logger().warn(
                'Loaded model labels do not match the project classes '
                '(gear, square_gear, nut, bearing). '
                f'This model will not produce usable detections here. Example labels: {preview}'
            )

    def _load_model(self):
        if not self.model_path:
            self.get_logger().error('Parameter model_path is empty. Set it to your YOLOv8 .pt weights file.')
            return None

        try:
            from ultralytics import YOLO
        except ImportError:
            self.get_logger().error(
                'ultralytics is not installed in the Python environment used by this node. '
                'Install it before launching yolo_vision_node.'
            )
            return None

        resolved_model_path = resolve_model_path(self.model_path)
        try:
            model = YOLO(resolved_model_path)
        except Exception as exc:
            self.get_logger().error(f'Failed to load YOLOv8 model from {resolved_model_path}: {exc}')
            return None

        self.get_logger().info(f'Loaded YOLOv8 model: {resolved_model_path}')
        return model

    # ── CameraInfo ──────────────────────────────────────────────────────
    def camera_info_callback(self, msg: CameraInfo):
        # Projection matrix P is [fx 0 cx Tx; 0 fy cy Ty; 0 0 1 0]
        # In ROS 2 it is msg.p (12‐element list, row‐major)
        self.fx = msg.p[0]
        self.fy = msg.p[5]
        self.cx = msg.p[2]
        self.cy = msg.p[6]

    # ── Main image callback ─────────────────────────────────────────────
    def image_callback(self, msg: Image):
        # Throttle
        now = self.get_clock().now()
        dt = (now - self.last_process_time).nanoseconds * 1e-9
        if dt < self.process_interval:
            return
        self.last_process_time = now

        # Convert to OpenCV BGR
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        # ── Run detection ───────────────────────────────────────────
        detections = detect_objects(
            cv_image,
            self.model,
            self.confidence_threshold,
            self.iou_threshold,
            self.input_size,
            self.device,
        )

        # ── Draw bounding boxes & publish ───────────────────────────
        annotated = cv_image.copy()

        if self.model is None:
            cv2.putText(
                annotated,
                'YOLOv8 model not loaded - check model_path / ultralytics',
                (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (100, 100, 255), 2,
            )
        elif len(detections) == 0:
            if self.model_supported_classes:
                overlay_text = 'YOLOv8: No supported detections'
            else:
                overlay_text = 'Model labels do not match gear/square_gear/nut/bearing'
            cv2.putText(
                annotated,
                overlay_text,
                (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (100, 100, 255), 2,
            )
        else:
            for det in detections:
                det['size_m'] = self._estimate_size_from_bbox(det['bbox'])
                self._draw_box(annotated, det)
                self._publish_detection(det, msg.header)

        # ── Publish annotated image ─────────────────────────────────
        annotated_msg = self.bridge.cv2_to_imgmsg(annotated, encoding='bgr8')
        annotated_msg.header = msg.header
        self.annotated_pub.publish(annotated_msg)

        # ── Show in OpenCV window ───────────────────────────────────
        if self.show_debug_window:
            cv2.imshow('YOLO Vision', annotated)
            cv2.waitKey(1)

    # ── Draw one bounding box on the image ──────────────────────────────
    def _draw_box(self, img: np.ndarray, det: dict):
        x1, y1, x2, y2 = det['bbox']
        cls_name = det.get('class', 'unknown')
        conf = det.get('confidence', 0.0)
        color = CLASS_COLORS.get(cls_name, CLASS_COLORS['unknown'])

        # Rectangle
        cv2.rectangle(img, (x1, y1), (x2, y2), color, 2)

        # Label background
        size_m = det.get('size_m', 0.0)
        if size_m > 0.0:
            label = f"{cls_name} {conf:.0%} {size_m * 100:.1f}cm"
        else:
            label = f"{cls_name} {conf:.0%}"
        (tw, th), _ = cv2.getTextSize(label, cv2.FONT_HERSHEY_SIMPLEX, 0.6, 1)
        cv2.rectangle(img, (x1, y1 - th - 8), (x1 + tw + 4, y1), color, -1)
        cv2.putText(img, label, (x1 + 2, y1 - 4), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 1)

    def _estimate_size_from_bbox(self, bbox) -> float:
        if self.fx is None or self.fy is None:
            return 0.0

        x1, y1, x2, y2 = bbox
        depth = self.cam_pos[2] - self.table_z
        width_m = max(0.0, (x2 - x1) * depth / self.fx)
        height_m = max(0.0, (y2 - y1) * depth / self.fy)
        return float(max(width_m, height_m))

    # ── Convert pixel centre → world XYZ & publish ─────────────────────
    def _publish_detection(self, det: dict, header):
        if self.fx is None:
            self.get_logger().warn('CameraInfo not yet received, skipping world‐coordinate publish')
            return

        x1, y1, x2, y2 = det['bbox']
        u = (x1 + x2) / 2.0
        v = (y1 + y2) / 2.0

        # Pinhole back‐projection (camera is looking straight down)
        # The depth from camera to table surface:
        depth = self.cam_pos[2] - self.table_z

        # Image‐frame → camera‐frame (optical frame: X-right, Y-down, Z-forward)
        # Then to world‐frame (camera points -Z world, but the optical frame
        # convention from MuJoCo ROS already handles this).
        # For a perfectly vertical overhead camera the mapping simplifies to:
        x_world = self.cam_pos[0] + (u - self.cx) * depth / self.fx
        y_world = self.cam_pos[1] - (v - self.cy) * depth / self.fy  # mirrored Y
        z_world = self.table_z

        # ── PoseStamped ─────────────────────────────────────────────
        pose_msg = PoseStamped()
        pose_msg.header.stamp = header.stamp
        pose_msg.header.frame_id = 'world'
        pose_msg.pose.position.x = float(x_world)
        pose_msg.pose.position.y = float(y_world)
        pose_msg.pose.position.z = float(z_world)
        pose_msg.pose.orientation.w = 1.0
        self.pose_pub.publish(pose_msg)

        # ── Part type ───────────────────────────────────────────────
        type_msg = String()
        type_msg.data = det.get('class', 'unknown')
        self.type_pub.publish(type_msg)

        # ── Part size ───────────────────────────────────────────────
        size_msg = Float32()
        size_msg.data = det.get('size_m', 0.04)
        self.size_pub.publish(size_msg)

        self.get_logger().info(
            f"Detected [{det['class']}] conf={det.get('confidence',0):.0%}  "
            f"world=({x_world:.3f}, {y_world:.3f}, {z_world:.3f})  "
            f"size={det.get('size_m',0.04):.3f}m"
        )


def main(args=None):
    rclpy.init(args=args)
    node = YoloVisionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if getattr(node, 'show_debug_window', False):
            cv2.destroyAllWindows()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
