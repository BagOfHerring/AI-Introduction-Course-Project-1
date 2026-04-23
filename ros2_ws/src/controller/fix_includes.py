import os

files_to_fix = [
    '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/cplus_dev/include/utilities_function/dist_interarm_sphere.h',
    '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/controller/src/ssa_controller.cpp',
    '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/cplus_dev/src/GBP_classes/factor_node/SSADistFNode.cpp',
    '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/cplus_dev/src/GBP_classes/factor_node/InterarmIntpFNode.cpp',
    '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/cplus_dev/src/GBP_classes/factor_node/DistFNode.cpp',
    '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/cplus_dev/src/GBP_classes/graph_env_message/Env.cpp',
    '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/cplus_dev/src/GBP_classes/graph_env_message/Agent.cpp',
    '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/controller/src/gbp_mpc_controller.cpp'
]

for filepath in files_to_fix:
    if os.path.exists(filepath):
        with open(filepath, 'r') as f:
            c = f.read()
        c = c.replace('#include "GBP_classes/Robot_classes/RobotDescription.h"', '#include "Robot_classes/RobotDescription.h"')
        c = c.replace('#include "GBP_classes/Robot_classes/CollisionSphere.h"', '#include "Robot_classes/CollisionSphere.h"')
        with open(filepath, 'w') as f:
            f.write(c)

print("Includes fixed.")
