import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, LogInfo
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    main_launch = os.path.join(
        get_package_share_directory('multi_launch'),
        'launch',
        'auto_multi_robot_control.launch.py',
    )

    return LaunchDescription([
        DeclareLaunchArgument('use_rviz', default_value='false'),
        DeclareLaunchArgument('enable_dynamic_obstacles', default_value='true'),
        LogInfo(msg='mixed_dual_multimode_franka.launch.py 已退役，当前仅保留 use_rviz 和 enable_dynamic_obstacles，并转发到 multi_launch 主控制入口。'),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(main_launch),
            launch_arguments={
                'use_rviz': LaunchConfiguration('use_rviz'),
                'enable_dynamic_obstacles': LaunchConfiguration('enable_dynamic_obstacles'),
            }.items(),
        ),
    ])
