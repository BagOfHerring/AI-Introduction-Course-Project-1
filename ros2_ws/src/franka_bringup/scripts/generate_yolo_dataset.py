#!/usr/bin/env python3
"""
Generate a labeled YOLO dataset from the MuJoCo overhead camera.

This script regenerates the scene, launches the simulator and vision node,
captures one overhead image, and writes YOLO labels derived from the exact
scene metadata emitted by generate_scene.py.
"""
import argparse
import json
import math
import os
import signal
import subprocess
import sys
import time
from pathlib import Path

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node
from sensor_msgs.msg import CameraInfo, Image


DATASET_CLASS_NAMES = ['bearing', 'square_gear', 'nut', 'gear']
CLASS_TO_ID = {name: index for index, name in enumerate(DATASET_CLASS_NAMES)}
ROS_WS = Path(__file__).resolve().parents[3]
WORKSPACE_ROOT = ROS_WS.parent
DEFAULT_DATASET_ROOT = WORKSPACE_ROOT / 'yolo_train'
DEFAULT_METADATA_PATH = ROS_WS / 'src' / 'franka_description' / 'mujoco' / 'franka' / 'scene_with_workbench.metadata.json'
GENERATE_SCENE_SCRIPT = Path(__file__).resolve().with_name('generate_scene.py')
SIM_LAUNCH_CMD = [
    'ros2', 'launch', 'franka_bringup', 'single_franka_sim.launch.py',
    'use_rviz:=false', 'headless:=true',
]
VISION_NODE_CMD = [
    'ros2', 'run', 'franka_bringup', 'yolo_vision_node.py',
    '--ros-args',
    '-p', f'model_path:={WORKSPACE_ROOT / "yolov8s.pt"}',
    '-p', 'show_debug_window:=false',
    '-p', 'process_interval:=10.0',
]


def ensure_layout(dataset_root: Path):
    for relative in (
        'images/train',
        'images/val',
        'labels/train',
        'labels/val',
    ):
        (dataset_root / relative).mkdir(parents=True, exist_ok=True)


def write_data_yaml(dataset_root: Path):
    content = (
        f'path: {dataset_root}\n'
        'train: images/train\n'
        'val: images/val\n'
        f'nc: {len(DATASET_CLASS_NAMES)}\n'
        'names:\n'
        '  0: bearing\n'
        '  1: square_gear\n'
        '  2: nut\n'
        '  3: gear\n'
    )
    (dataset_root / 'data.yaml').write_text(content, encoding='utf-8')


def write_labelimg_classes_files(dataset_root: Path):
    content = '\n'.join(DATASET_CLASS_NAMES) + '\n'
    for relative in ('labels/train/classes.txt', 'labels/val/classes.txt'):
        (dataset_root / relative).write_text(content, encoding='utf-8')


def split_name(index: int) -> str:
    return 'val' if index % 3 == 0 else 'train'


def normalize_label(x_center, y_center, width, height, image_width, image_height):
    return (
        x_center / image_width,
        y_center / image_height,
        width / image_width,
        height / image_height,
    )


def rotation_matrix_z(yaw_rad: float) -> np.ndarray:
    cos_yaw = math.cos(yaw_rad)
    sin_yaw = math.sin(yaw_rad)
    return np.array([
        [cos_yaw, -sin_yaw, 0.0],
        [sin_yaw, cos_yaw, 0.0],
        [0.0, 0.0, 1.0],
    ], dtype=np.float64)


def project_world_to_pixel(point_xyz, intrinsics, camera_xyz):
    fx, fy, cx, cy = intrinsics
    cam_x, cam_y, cam_z = camera_xyz
    x_world, y_world, z_world = point_xyz
    depth = cam_z - z_world
    if depth <= 0.0:
        raise ValueError('Projected point is behind the overhead camera.')
    u = cx + (x_world - cam_x) * fx / depth
    v = cy - (y_world - cam_y) * fy / depth
    return u, v


def part_bbox_pixels(part: dict, intrinsics, camera_xyz, image_width: int, image_height: int):
    center = np.array(part['position_xyz'], dtype=np.float64)
    dims = part['dimensions_m']
    half_sizes = np.array([dims['x'], dims['y'], dims['z']], dtype=np.float64) / 2.0
    rotation = rotation_matrix_z(float(part['yaw_rad']))

    projected = []
    for sx in (-1.0, 1.0):
        for sy in (-1.0, 1.0):
            for sz in (-1.0, 1.0):
                local = np.array([
                    sx * half_sizes[0],
                    sy * half_sizes[1],
                    sz * half_sizes[2],
                ], dtype=np.float64)
                world = center + rotation @ local
                projected.append(project_world_to_pixel(world, intrinsics, camera_xyz))

    us = [value[0] for value in projected]
    vs = [value[1] for value in projected]

    x_min = max(0.0, min(us))
    y_min = max(0.0, min(vs))
    x_max = min(float(image_width - 1), max(us))
    y_max = min(float(image_height - 1), max(vs))
    if x_max <= x_min or y_max <= y_min:
        return None
    return x_min, y_min, x_max, y_max


class SingleFrameCollector(Node):
    def __init__(self):
        super().__init__('single_frame_collector')
        self.bridge = CvBridge()
        self.image_msg = None
        self.info_msg = None
        self.image_sub = self.create_subscription(
            Image,
            '/mujoco_server/cameras/vision_cam/rgb/image_raw',
            self._image_callback,
            10,
        )
        self.info_sub = self.create_subscription(
            CameraInfo,
            '/mujoco_server/cameras/vision_cam/rgb/camera_info',
            self._info_callback,
            10,
        )

    def _image_callback(self, msg: Image):
        if self.image_msg is None:
            self.image_msg = msg

    def _info_callback(self, msg: CameraInfo):
        if self.info_msg is None:
            self.info_msg = msg

    def wait_for_frame(self, timeout_sec: float):
        deadline = time.time() + timeout_sec
        while time.time() < deadline:
            rclpy.spin_once(self, timeout_sec=0.2)
            if self.image_msg is not None and self.info_msg is not None:
                image = self.bridge.imgmsg_to_cv2(self.image_msg, desired_encoding='bgr8')
                return image, self.info_msg
        raise TimeoutError('Timed out waiting for vision_cam image and camera_info.')


def launch_process(command, env, cwd: Path):
    return subprocess.Popen(
        command,
        cwd=str(cwd),
        env=env,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        preexec_fn=os.setsid,
    )


def stop_process(process: subprocess.Popen):
    if process.poll() is not None:
        return
    os.killpg(os.getpgid(process.pid), signal.SIGTERM)
    try:
        process.wait(timeout=10)
    except subprocess.TimeoutExpired:
        os.killpg(os.getpgid(process.pid), signal.SIGKILL)
        process.wait(timeout=5)


def generate_scene(seed: int, metadata_path: Path):
    command = [
        sys.executable,
        str(GENERATE_SCENE_SCRIPT),
        '--seed', str(seed),
        '--dataset-mode',
        '--metadata', str(metadata_path),
    ]
    subprocess.run(command, cwd=str(ROS_WS), check=True)
    return json.loads(metadata_path.read_text(encoding='utf-8'))


def wait_for_ros_graph(env, timeout_sec: float = 20.0):
    deadline = time.time() + timeout_sec
    while time.time() < deadline:
        result = subprocess.run(
            ['ros2', 'topic', 'list'],
            cwd=str(ROS_WS),
            env=env,
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
            text=True,
        )
        if '/mujoco_server/cameras/vision_cam/rgb/image_raw' in result.stdout:
            return
        time.sleep(0.5)
    raise TimeoutError('MuJoCo camera topics did not appear in time.')


def write_labels(label_path: Path, metadata: dict, camera_info: CameraInfo, image_shape):
    height, width = image_shape[:2]
    fx = float(camera_info.p[0])
    fy = float(camera_info.p[5])
    cx = float(camera_info.p[2])
    cy = float(camera_info.p[6])
    intrinsics = (fx, fy, cx, cy)
    camera_xyz = tuple(metadata['camera']['position_xyz'])

    lines = []
    for part in metadata['parts']:
        bbox = part_bbox_pixels(part, intrinsics, camera_xyz, width, height)
        if bbox is None:
            continue
        x_min, y_min, x_max, y_max = bbox
        x_center = (x_min + x_max) / 2.0
        y_center = (y_min + y_max) / 2.0
        box_width = x_max - x_min
        box_height = y_max - y_min
        x_center_n, y_center_n, width_n, height_n = normalize_label(
            x_center,
            y_center,
            box_width,
            box_height,
            width,
            height,
        )
        class_id = CLASS_TO_ID[part['part_type']]
        lines.append(
            f'{class_id} {x_center_n:.6f} {y_center_n:.6f} {width_n:.6f} {height_n:.6f}'
        )
    label_path.write_text('\n'.join(lines) + ('\n' if lines else ''), encoding='utf-8')


def main():
    parser = argparse.ArgumentParser(description='Generate a YOLO dataset from the MuJoCo overhead camera.')
    parser.add_argument('--count', type=int, default=100, help='Number of samples to generate.')
    parser.add_argument('--start-index', type=int, default=1, help='1-based dataset index to start from.')
    parser.add_argument('--dataset-root', type=Path, default=DEFAULT_DATASET_ROOT, help='Root folder for yolo_train.')
    parser.add_argument('--metadata-path', type=Path, default=DEFAULT_METADATA_PATH, help='Temporary metadata JSON path.')
    parser.add_argument('--capture-timeout', type=float, default=30.0, help='Seconds to wait for one frame.')
    parser.add_argument('--max-retries', type=int, default=3, help='How many times to retry one sample after a timeout.')
    args = parser.parse_args()

    dataset_root = args.dataset_root.resolve()
    metadata_path = args.metadata_path.resolve()
    ensure_layout(dataset_root)
    write_data_yaml(dataset_root)
    write_labelimg_classes_files(dataset_root)

    env = os.environ.copy()
    env['PYTHONUNBUFFERED'] = '1'

    rclpy.init(args=None)
    try:
        for offset in range(args.count):
            sample_index = args.start_index + offset
            split = split_name(sample_index)
            stem = f'image_{sample_index:03d}'
            image_path = dataset_root / 'images' / split / f'{stem}.jpg'
            label_path = dataset_root / 'labels' / split / f'{stem}.txt'

            metadata = generate_scene(seed=sample_index, metadata_path=metadata_path)
            last_timeout = None
            for attempt in range(1, args.max_retries + 1):
                sim_process = None
                vision_process = None
                collector = None
                try:
                    sim_process = launch_process(SIM_LAUNCH_CMD, env=env, cwd=ROS_WS)
                    wait_for_ros_graph(env)
                    vision_process = launch_process(VISION_NODE_CMD, env=env, cwd=ROS_WS)
                    time.sleep(2.0)

                    collector = SingleFrameCollector()
                    image, camera_info = collector.wait_for_frame(timeout_sec=args.capture_timeout)
                    cv2.imwrite(str(image_path), image)
                    write_labels(label_path, metadata, camera_info, image.shape)
                    print(f'[{sample_index}/{args.start_index + args.count - 1}] saved {image_path.name} -> {split}')
                    last_timeout = None
                    break
                except TimeoutError as error:
                    last_timeout = error
                    print(
                        f'[{sample_index}/{args.start_index + args.count - 1}] '
                        f'attempt {attempt}/{args.max_retries} timed out waiting for camera data; retrying...',
                        file=sys.stderr,
                        flush=True,
                    )
                finally:
                    if collector is not None:
                        collector.destroy_node()
                    if vision_process is not None:
                        stop_process(vision_process)
                    if sim_process is not None:
                        stop_process(sim_process)

            if last_timeout is not None:
                raise last_timeout
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()