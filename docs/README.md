# 人智导大作业：ROS 2 + MuJoCo + Franka 视觉抓取仿真

这个项目是一个基于 ROS 2、MuJoCo 和 Franka Panda 机械臂的课程大作业原型。系统目标是搭建一个完整的仿真闭环：在桌面场景中生成零件，使用视觉节点识别零件的位置与类别，再把检测结果发送给机械臂执行抓取。

当前仓库已经具备以下主链路：

- MuJoCo 仿真环境与 Franka 单臂启动
- 桌面场景、相机和零件模型定义
- 零件随机化脚本
- YOLOv8 视觉检测节点
- 基于检测结果的抓取执行节点

同时也要说明一个事实：当前代码里的视觉检测已经接入 YOLOv8 推理，但如果没有项目自己的四分类权重，默认只能先用通用的 yolov8s.pt 做流程联调。README 下面会把“设计目标”和“当前实际状态”分开写清楚。

## 1. 项目目标

项目想完成的完整流程如下：

1. 启动 MuJoCo 仿真，加载 Franka Panda 机械臂、桌面和俯视相机。
2. 在桌面上随机摆放 8 个零件。
3. 用视觉节点读取相机图像，并调用 YOLO 检测零件。
4. 发布零件的类别、位置和尺寸信息。
5. 抓取节点订阅检测结果，计算机械臂运动并执行夹取。

## 2. 系统组成

### 2.1 仿真环境

- 机械臂启动入口：ros2_ws/src/franka_bringup/launch/sim/single_franka_sim.launch.py
- 场景文件：ros2_ws/src/franka_description/mujoco/franka/scene_with_workbench.xml

single_franka_sim.launch.py 负责启动：

- MuJoCo 仿真服务端
- Panda 机器人描述与状态发布
- ros2_control 控制器
- Panda 轨迹控制器和状态广播器

scene_with_workbench.xml 负责定义：

- Franka Panda 机械臂模型
- 桌面 workbench
- 俯视相机 vision_cam
- 供抓取使用的零件模型

注意：这个 launch 文件本身只负责仿真和控制器，不会自动启动视觉节点、零件随机化节点或抓取节点。这几个脚本需要额外在终端里单独启动。

### 2.2 零件生成与随机化

相关文件：

- ros2_ws/src/franka_bringup/scripts/generate_scene.py

generate_scene.py 用于生成包含 8 个零件的 MuJoCo 场景描述，并且会随机化零件的外观材质。

设计上，零件一共 4 类，每类 2 个，共 8 个：

- gear
- square_gear
- nut
- bearing

当前脚本除了随机位置和质量之外，还会给零件随机分配不同的外观预设，例如金属、木质、塑料和深色陶瓷风格，便于做更丰富的仿真展示和视觉训练。

### 2.3 视觉检测节点

相关文件：

- ros2_ws/src/franka_bringup/scripts/yolo_vision_node.py
- ros2_ws/src/franka_bringup/scripts/mock_vision_node.py

yolo_vision_node.py 的职责是：

- 订阅 MuJoCo 相机图像
- 读取相机内参
- 调用目标检测函数 detect_objects
- 把检测框中心投影回桌面世界坐标
- 发布零件位姿、类型、尺寸和标注图像

主要话题如下：

- 订阅：/mujoco_server/cameras/vision_cam/rgb/image_raw
- 订阅：/mujoco_server/cameras/vision_cam/rgb/camera_info
- 发布：/vision_detector/part_pose
- 发布：/vision_detector/part_type
- 发布：/vision_detector/part_size
- 发布：/vision_detector/annotated_image

mock_vision_node.py 是一个调试节点，会周期性发布一个假的目标位姿，适合在没有真实视觉检测时验证后续抓取链路。

### 2.4 抓取执行节点

相关文件：

- ros2_ws/src/franka_bringup/scripts/pick_and_place.py

这个节点的职责是：

- 订阅视觉节点发出的目标位置
- 订阅目标类型
- 调用解析 IK 求解目标位姿对应的关节角
- 向机械臂轨迹控制器发送 FollowJointTrajectory 动作
- 向夹爪发送 GripperCommand 动作
- 执行一个简单的抓取与放置序列

它使用的接口包括：

- /vision_detector/part_pose
- /vision_detector/part_type
- /panda_joint_trajectory_controller/follow_joint_trajectory
- /panda_gripper_sim_node/gripper_action

## 3. 功能和文件的对应关系

如果你答辩时需要快速指出“哪个功能在哪个文件里”，可以直接按下面这张表来讲：

| 功能 | 对应文件 |
| --- | --- |
| 启动 MuJoCo 单臂仿真 | ros2_ws/src/franka_bringup/launch/sim/single_franka_sim.launch.py |
| 定义桌面、相机和零件场景 | ros2_ws/src/franka_description/mujoco/franka/scene_with_workbench.xml |
| 离线生成 8 个随机零件场景 | ros2_ws/src/franka_bringup/scripts/generate_scene.py |
| YOLO 视觉检测节点框架 | ros2_ws/src/franka_bringup/scripts/yolo_vision_node.py |
| 假数据视觉节点 | ros2_ws/src/franka_bringup/scripts/mock_vision_node.py |
| 接收检测结果并执行抓取 | ros2_ws/src/franka_bringup/scripts/pick_and_place.py |
| 单臂仿真控制器参数 | ros2_ws/src/franka_bringup/config/sim/single_sim_controllers.yaml |

## 4. 当前仓库的真实状态

这一节很重要，建议你答辩时按真实情况表述。

### 4.1 已经接通的部分

- 单臂 MuJoCo 仿真可以通过 launch 文件启动。
- 场景里已经有桌面和俯视相机。
- pick_and_place.py 已经实现抓取流程框架，并能接收视觉节点输出的话题。

### 4.2 还没有完全接通的部分

- yolo_vision_node.py 已经接入真实 YOLOv8 推理，也支持直接加载或自动下载 yolov8s.pt。
- 但如果要稳定识别当前项目里的 4 类工件，仍然需要你自己的训练权重，比如 best.pt。
- pick_and_place.py 当前实际使用的是目标位置和类型，没有使用 /vision_detector/part_size。
- single_franka_sim.launch.py 不会自动拉起视觉和抓取脚本，这部分需要手动另开终端启动。

### 4.3 关于“8 个随机零件”的说明

当前保留的是离线生成机制：generate_scene.py 负责生成包含 8 个零件的场景描述。

也就是说，如果你要演示“每次启动前刷新一批新的零件布局”，现在的做法是先运行 generate_scene.py 重写场景文件，再重新启动仿真。

## 5. 推荐运行方式

以下命令都在 ros2_ws 目录下执行。

### 5.1 编译

```bash
cd /home/herring/rzddzy/ros2_ws
colcon build --symlink-install
source install/setup.bash
```

### 5.2 启动 MuJoCo 仿真

带界面启动：

```bash
ros2 launch franka_bringup single_franka_sim.launch.py use_rviz:=false headless:=false
```

无界面启动：

```bash
ros2 launch franka_bringup single_franka_sim.launch.py use_rviz:=false headless:=true
```

### 5.3 可选：启动前重新生成随机场景

如果你希望在启动仿真前生成一份新的 8 零件场景，并刷新零件的外观材质，可以执行：

```bash
cd /home/herring/rzddzy/ros2_ws/src/franka_bringup/scripts
python3 generate_scene.py
```

然后回到 ros2_ws，至少重新编译 franka_description，再启动仿真：

```bash
cd /home/herring/rzddzy/ros2_ws
colcon build --packages-select franka_description --symlink-install
source install/setup.bash
```

### 5.4 启动视觉与抓取

如果你要先验证 YOLO 节点、GPU 和 ROS 图像链路已经打通，可以直接使用：

终端 3：

```bash
cd /home/herring/rzddzy/ros2_ws
source install/setup.bash
ros2 run franka_bringup yolo_vision_node.py --ros-args -p model_path:=yolov8s.pt -p device:=0
```

这条命令第一次运行时会自动下载 yolov8s.pt，并使用 GPU 0 推理。

当前默认不会弹出 OpenCV 调试窗口，因此也不会再出现 Qt 字体目录相关警告。如果你本地确实需要看检测预览，可以额外加上参数：-p show_debug_window:=true。

如果你已经训练好了自己的四分类权重，推荐改成：

```bash
cd /home/herring/rzddzy/ros2_ws
source install/setup.bash
ros2 run franka_bringup yolo_vision_node.py --ros-args -p model_path:=/你的权重路径/best.pt -p device:=0
```

注意：通用的 yolov8s.pt 主要用于联调流程，本身并不认识你这 4 类工件。

终端 4：

```bash
cd /home/herring/rzddzy/ros2_ws
source install/setup.bash
ros2 run franka_bringup pick_and_place.py
```

如果你现在只是想演示抓取链路是否打通，建议先用假视觉节点替代 YOLO：

终端 3：

```bash
cd /home/herring/rzddzy/ros2_ws
source install/setup.bash
ros2 run franka_bringup mock_vision_node.py
```

终端 4：

```bash
cd /home/herring/rzddzy/ros2_ws
source install/setup.bash
ros2 run franka_bringup pick_and_place.py
```

## 6. 适合答辩时的项目描述

如果你需要一句比较正式、又和代码相符的项目简介，可以直接这样说：

本项目实现了一个基于 ROS 2 与 MuJoCo 的 Franka Panda 单臂抓取仿真系统。系统在桌面场景中构建了机械臂、俯视相机和待抓取零件，并设计了零件随机化、视觉检测和抓取执行三部分模块。当前仓库已经完成仿真环境搭建、抓取执行链路和 YOLOv8 视觉节点接入；如果需要准确识别课程场景中的 4 类工件，还需要补充项目专用训练权重。

## 7. 后续可继续完善的点

如果你之后还要继续完善这个项目，优先级建议如下：

1. 训练并接入当前 4 类工件的专用 YOLO 权重，例如 best.pt。
2. 统一 generate_scene.py 和 scene_with_workbench.xml 的零件命名与场景生成流程。
3. 让 launch 文件直接把视觉节点和抓取节点一起拉起，减少手工启动步骤。
4. 在 pick_and_place.py 里真正利用 part_size 和 part_type 做不同抓取策略。
