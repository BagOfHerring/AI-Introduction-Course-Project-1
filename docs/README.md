# ROS 2 + MuJoCo + Franka 拷贝目录说明

当前环境无法直接写入根目录 `/rzddzy`，因为需要 root 密码。
所以这份内容先暂存到了 `/tmp/rzddzy`，目录结构已经按最终目标 `/rzddzy` 设计好了。
如果你之后要放到根目录，执行下面这条命令即可：

```bash
sudo cp -a /tmp/rzddzy /rzddzy
```

这个目录是从 `MR-GBP` 项目中整理出来的可复用部分，目标是给 `ROS 2 (Jazzy) + MuJoCo` 单臂 Franka 仿真做基础。

## 目录总览

- `/rzddzy/ros2_ws/src/controller`
  - 你的 ROS 2 控制器包。
- `/rzddzy/ros2_ws/src/cplus_dev`
  - `controller` 的核心依赖，里面包含 `MRGBP.yaml` 等配置。
- `/rzddzy/ros2_ws/src/franka_bringup`
  - Franka 的启动入口，包含 MuJoCo 仿真 launch。
- `/rzddzy/ros2_ws/src/franka_description`
  - Franka 机械臂模型：
    - URDF/Xacro: `robots/sim/panda_arm_sim.urdf.xacro`
    - MuJoCo XML: `mujoco/franka/scene.xml`、`mujoco/franka/TEMPLATE_panda.xml`
    - 网格模型: `meshes/visual/*`
- `/rzddzy/ros2_ws/src/franka_hardware`
  - Franka 的 MuJoCo `ros2_control` 硬件接口实现。
- `/rzddzy/ros2_ws/src/franka_msgs`
  - Franka 自定义消息。
- `/rzddzy/ros2_ws/src/franka_robot_state_broadcaster`
  - Franka 状态广播器。
- `/rzddzy/ros2_ws/src/franka_semantic_components`
  - 状态广播器和控制器依赖。
- `/rzddzy/ros2_ws/src/franka_example_controllers`
  - 仓库自带示例控制器。
- `/rzddzy/ros2_ws/src/multi_mode_controller`
  - 多模态控制器接口层。
- `/rzddzy/ros2_ws/src/multi_mode_controller_impl`
  - 多模态控制器实现层。
- `/rzddzy/ros2_ws/src/multi_mode_control_msgs`
  - 多模态控制消息。
- `/rzddzy/ros2_ws/src/panda_motion_generator_msgs`
  - Panda 运动生成消息。
- `/rzddzy/ros2_ws/src/panda_motion_generators`
  - Panda 运动生成节点。
- `/rzddzy/ros2_ws/src/mujoco_ros_pkgs`
  - MuJoCo ROS 相关包，`franka_hardware` 编译时会依赖这里的相对路径。

## 直接可用的关键入口

- 单臂仿真启动文件：
  - `/rzddzy/ros2_ws/src/franka_bringup/launch/sim/single_franka_sim.launch.py`
- 单臂仿真 controller 配置：
  - `/rzddzy/ros2_ws/src/franka_bringup/config/sim/single_sim_controllers.yaml`
- Franka 单臂仿真 URDF：
  - `/rzddzy/ros2_ws/src/franka_description/robots/sim/panda_arm_sim.urdf.xacro`
- Franka MuJoCo 场景模板：
  - `/rzddzy/ros2_ws/src/franka_description/mujoco/franka/scene.xml`
  - `/rzddzy/ros2_ws/src/franka_description/mujoco/franka/TEMPLATE_panda.xml`
- 你的 MRGBP 配置：
  - `/rzddzy/ros2_ws/src/cplus_dev/config/MRGBP.yaml`
- 你的 ROS 2 控制器源码：
  - `/rzddzy/ros2_ws/src/controller/src/gbp_mpc_controller.cpp`
  - `/rzddzy/ros2_ws/src/controller/src/buffer_controller.cpp`
  - `/rzddzy/ros2_ws/src/controller/src/ssa_controller.cpp`

## 兼容性说明

- 这次主路径里复制的是 `ros2_ws/src/controller` 这份 ROS 2 版本控制器。
- 另外还保留了一份旧的 ROS 1 `catkin` 控制器参考：
  - `/rzddzy/legacy_ros1/controller`
- `legacy_ros1/controller` 不能直接在 ROS 2 Jazzy 里原样编译，它主要是给你做对照参考。

## 你后面最可能先用到的命令

在 `/rzddzy/ros2_ws` 下：

```bash
colcon build --symlink-install
source install/setup.bash
ros2 launch franka_bringup single_franka_sim.launch.py use_rviz:=false headless:=false
```

如果只想无界面跑仿真：

```bash
ros2 launch franka_bringup single_franka_sim.launch.py use_rviz:=false headless:=true
```
