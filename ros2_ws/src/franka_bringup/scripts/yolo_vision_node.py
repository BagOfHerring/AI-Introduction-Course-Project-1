#!/usr/bin/env python3
"""
YOLO Vision Detection Node
===========================
Subscribes to the MuJoCo overhead camera, runs object detection (placeholder API),
draws bounding boxes on the image, and publishes part type/size/world coordinates
to the pick-and-place pipeline.

YOLO integration is left as a placeholder function `detect_objects()`.
Replace it with a real model call when ready.
"""
import math
import numpy as np
import cv2

import rclpy
from rclpy.node import Node
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
    'bolt':        (0, 255, 255),   # cyan
    'unknown':     (180, 180, 180), # gray
}


# ═══════════════════════════════════════════════════════════════════════════
#  YOLO Placeholder API  –  replace the body of this function with your model
# ═══════════════════════════════════════════════════════════════════════════
def detect_objects(cv_image: np.ndarray) -> list:
    """
    Run object detection on a single BGR image.

    Returns a list of detections, each being a dict:
        {
            'class':      str,          # e.g. 'gear', 'nut', 'bearing', ...
            'confidence': float,        # 0‥1
            'bbox':       (x1, y1, x2, y2),  # pixel coordinates, top-left & bottom-right
            'size_m':     float,        # estimated real-world diameter / width in meters
        }

    *** CURRENT IMPLEMENTATION: returns an empty list (no detections). ***
    *** Plug in your YOLO model here later (e.g. ultralytics).        ***

    Example with ultralytics (uncomment when ready):
    ──────────────────────────────────────────────────
    from ultralytics import YOLO
    model = YOLO('best.pt')
    results = model(cv_image, conf=0.5)
    detections = []
    for r in results:
        for box in r.boxes:
            x1, y1, x2, y2 = box.xyxy[0].tolist()
            cls_id = int(box.cls[0])
            cls_name = model.names[cls_id]
            conf = float(box.conf[0])
            detections.append({
                'class': cls_name,
                'confidence': conf,
                'bbox': (int(x1), int(y1), int(x2), int(y2)),
                'size_m': 0.04,
            })
    return detections
    """
    return []


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
        self.get_logger().info('  (detect_objects() is currently a placeholder – returns no detections)')

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

        # ── Run detection (placeholder) ─────────────────────────────
        detections = detect_objects(cv_image)

        # ── Draw bounding boxes & publish ───────────────────────────
        annotated = cv_image.copy()

        if len(detections) == 0:
            # No detections – just show info bar
            cv2.putText(
                annotated,
                'YOLO: No detections (placeholder mode)',
                (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (100, 100, 255), 2,
            )
        else:
            for det in detections:
                self._draw_box(annotated, det)
                self._publish_detection(det, msg.header)

        # ── Publish annotated image ─────────────────────────────────
        annotated_msg = self.bridge.cv2_to_imgmsg(annotated, encoding='bgr8')
        annotated_msg.header = msg.header
        self.annotated_pub.publish(annotated_msg)

        # ── Show in OpenCV window ───────────────────────────────────
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
        label = f"{cls_name} {conf:.0%}"
        (tw, th), _ = cv2.getTextSize(label, cv2.FONT_HERSHEY_SIMPLEX, 0.6, 1)
        cv2.rectangle(img, (x1, y1 - th - 8), (x1 + tw + 4, y1), color, -1)
        cv2.putText(img, label, (x1 + 2, y1 - 4), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 1)

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
        cv2.destroyAllWindows()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
