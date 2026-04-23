#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
import cv2
from cv_bridge import CvBridge

class VisionPipelineNode(Node):
    def __init__(self):
        super().__init__('vision_pipeline_node')
        
        self.bridge = CvBridge()
        
        # Subscribe to MuJoCo camera topics
        self.image_sub = self.create_subscription(
            Image,
            '/mujoco_server/cameras/vision_cam/rgb/image_raw',
            self.image_callback,
            10
        )
        
        self.camera_info_sub = self.create_subscription(
            CameraInfo,
            '/mujoco_server/cameras/vision_cam/rgb/camera_info',
            self.camera_info_callback,
            10
        )
        
        self.camera_matrix = None
        self.get_logger().info('Vision Pipeline Node started. Waiting for camera data...')

    def camera_info_callback(self, msg):
        # Store Camera Intrinsic Matrix (K) for 3D projection mathematical operations
        self.camera_matrix = msg.k
        
    def image_callback(self, msg):
        try:
            # Convert ROS 2 Image message to OpenCV format
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            
            # --- AI LOGIC PLACEHOLDER ---
            # 1. Run inference (e.g., YOLO, Mask R-CNN, or template matching) on `cv_image` to detect gears, bearings, bolts.
            # 2. Extract bounding boxes or segmentation masks.
            # 3. Calculate the center pixel coordinates (u, v) in the 2D image.
            # 4. Use self.camera_matrix and optionally a depth map from the Depth Camera to de-project (u, v) into 3D Cartesian space (X, Y, Z).
            # 5. Transform from the camera frame (`vision_cam_optical_frame`) to robot base frame (`panda_link0`) using tf2 to get coordinates for Grasping.
            
            # Example visualization
            # cv2.imshow("Vision Camera stream", cv_image)
            # cv2.waitKey(1)
            pass
            
        except Exception as e:
            self.get_logger().error(f"Image processing failed: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = VisionPipelineNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
