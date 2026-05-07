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
    workspace_root = Path(__file__).resolve().parents[4]
    candidates = [
        Path.cwd() / model_path,
        script_dir / model_path,
        script_dir / 'weights' / model_path,
        workspace_root / model_path,
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


def bbox_iou(box_a, box_b) -> float:
    ax1, ay1, ax2, ay2 = box_a
    bx1, by1, bx2, by2 = box_b

    inter_x1 = max(ax1, bx1)
    inter_y1 = max(ay1, by1)
    inter_x2 = min(ax2, bx2)
    inter_y2 = min(ay2, by2)

    inter_w = max(0, inter_x2 - inter_x1)
    inter_h = max(0, inter_y2 - inter_y1)
    inter_area = inter_w * inter_h
    if inter_area <= 0:
        return 0.0

    area_a = max(1, ax2 - ax1) * max(1, ay2 - ay1)
    area_b = max(1, bx2 - bx1) * max(1, by2 - by1)
    union_area = area_a + area_b - inter_area
    if union_area <= 0:
        return 0.0

    return float(inter_area / union_area)


def suppress_cross_class_duplicates(detections: list[dict], iou_threshold: float) -> list[dict]:
    filtered = []
    for candidate in detections:
        if any(bbox_iou(candidate['bbox'], kept['bbox']) >= iou_threshold for kept in filtered):
            continue
        filtered.append(candidate)
    return filtered


class YoloVisionNode(Node):
    def __init__(self):
        super().__init__('yolo_vision_node')

        self.bridge = CvBridge()

        # ── Camera intrinsics (filled by CameraInfo callback) ───────────
        self.fx = None
        self.fy = None
        self.cx = None
        self.cy = None
        self.pixel_to_world_matrix = None
        self.logged_pixel_to_world_matrix = False

        self.declare_parameter('camera_position', [0.5, 0.0, 1.4])
        self.declare_parameter('table_z', 0.4)
        self.cam_pos = self._read_camera_position_parameter()
        self.table_z = float(self.get_parameter('table_z').value)

        # ── YOLO model parameters ───────────────────────────────────
        self.declare_parameter('model_path', 'best.pt')
        self.declare_parameter('confidence_threshold', 0.5)
        self.declare_parameter('iou_threshold', 0.45)
        self.declare_parameter('input_size', 640)
        self.declare_parameter(
            'device',
            'cuda:0',
            descriptor=ParameterDescriptor(dynamic_typing=True),
        )
        self.declare_parameter('show_debug_window', False)
        self.declare_parameter('cross_class_nms_iou', 0.35)

        self.model_path = self.get_parameter('model_path').value
        self.confidence_threshold = float(self.get_parameter('confidence_threshold').value)
        self.iou_threshold = float(self.get_parameter('iou_threshold').value)
        self.input_size = int(self.get_parameter('input_size').value)
        self.device = normalize_device_parameter(self.get_parameter('device').value)
        self.show_debug_window = bool(self.get_parameter('show_debug_window').value)
        self.cross_class_nms_iou = float(self.get_parameter('cross_class_nms_iou').value)
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

        if self.device.startswith('cuda'):
            try:
                import torch
            except ImportError:
                self.get_logger().warn(
                    'PyTorch is unavailable while device is set to CUDA. Falling back to CPU inference.'
                )
                self.device = 'cpu'
            else:
                if torch.cuda.is_available():
                    device_index = 0
                    if ':' in self.device:
                        try:
                            device_index = int(self.device.split(':', 1)[1])
                        except ValueError:
                            device_index = 0
                    gpu_name = torch.cuda.get_device_name(device_index)
                    self.get_logger().info(
                        f'Using GPU inference on {self.device} ({gpu_name})'
                    )
                else:
                    self.get_logger().warn(
                        'CUDA was requested for YOLOv8 inference, but no CUDA device is available. '
                        'Falling back to CPU.'
                    )
                    self.device = 'cpu'

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
        self._update_pixel_to_world_matrix()

    def _read_camera_position_parameter(self) -> np.ndarray:
        raw_value = self.get_parameter('camera_position').value
        try:
            camera_position = np.asarray(raw_value, dtype=float)
        except (TypeError, ValueError):
            camera_position = np.array([0.5, 0.0, 1.4], dtype=float)

        if camera_position.shape != (3,):
            self.get_logger().warn(
                'Parameter camera_position must contain exactly three values. '
                'Falling back to [0.5, 0.0, 1.4].'
            )
            return np.array([0.5, 0.0, 1.4], dtype=float)

        return camera_position

    def _update_pixel_to_world_matrix(self):
        if None in (self.fx, self.fy, self.cx, self.cy):
            self.pixel_to_world_matrix = None
            return

        depth = self.cam_pos[2] - self.table_z
        # scene_with_workbench.xml defines vision_cam with xyaxes="0 -1 0 1 0 0"
        # so image u points along -world Y and image v points along -world X.
        self.pixel_to_world_matrix = np.array(
            [
                [0.0, -depth / self.fy, self.cam_pos[0] + depth * self.cy / self.fy],
                [-depth / self.fx, 0.0, self.cam_pos[1] + depth * self.cx / self.fx],
                [0.0, 0.0, 1.0],
            ],
            dtype=float,
        )

        if not self.logged_pixel_to_world_matrix:
            matrix = np.array2string(self.pixel_to_world_matrix, precision=6, suppress_small=True)
            self.get_logger().info(f'Pixel-to-world matrix ready:\n{matrix}')
            self.logged_pixel_to_world_matrix = True

    def _transform_pixel_to_world_xy(self, u: float, v: float) -> Optional[np.ndarray]:
        if self.pixel_to_world_matrix is None:
            return None

        world_xy = self.pixel_to_world_matrix @ np.array([u, v, 1.0], dtype=float)
        return world_xy[:2]

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
        detections = suppress_cross_class_duplicates(detections, self.cross_class_nms_iou)

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
        if self.pixel_to_world_matrix is None:
            return 0.0

        x1, y1, x2, y2 = bbox
        top_left = self._transform_pixel_to_world_xy(x1, y1)
        top_right = self._transform_pixel_to_world_xy(x2, y1)
        bottom_left = self._transform_pixel_to_world_xy(x1, y2)
        if top_left is None or top_right is None or bottom_left is None:
            return 0.0

        width_m = float(np.linalg.norm(top_right - top_left))
        height_m = float(np.linalg.norm(bottom_left - top_left))
        return float(max(width_m, height_m))

    # ── Convert pixel centre → world XYZ & publish ─────────────────────
    def _publish_detection(self, det: dict, header):
        if self.pixel_to_world_matrix is None:
            self.get_logger().warn('CameraInfo not yet received, skipping world‐coordinate publish')
            return

        x1, y1, x2, y2 = det['bbox']
        u = (x1 + x2) / 2.0
        v = (y1 + y2) / 2.0

        world_xy = self._transform_pixel_to_world_xy(u, v)
        if world_xy is None:
            self.get_logger().warn('Pixel-to-world matrix unavailable, skipping publish')
            return

        x_world = float(world_xy[0])
        y_world = float(world_xy[1])
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
