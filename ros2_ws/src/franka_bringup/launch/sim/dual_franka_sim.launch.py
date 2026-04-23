#  Copyright (c) 2021 Franka Emika GmbH
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.


import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.launch_description_sources import FrontendLaunchDescriptionSource
from launch.actions import DeclareLaunchArgument, GroupAction, IncludeLaunchDescription, Shutdown
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node, PushRosNamespace
from launch_ros.substitutions import FindPackageShare
def concatenate_ns(ns1, ns2, absolute=False):
    
    if(len(ns1) == 0):
        return ns2
    if(len(ns2) == 0):
        return ns1
    
    # check for /s at the end and start
    if(ns1[0] == '/'):
        ns1 = ns1[1:]
    if(ns1[-1] == '/'):
        ns1 = ns1[:-1]
    if(ns2[0] == '/'):
        ns2 = ns2[1:]
    if(ns2[-1] == '/'):
        ns2 = ns2[:-1]
    if(absolute):
        ns1 = '/' + ns1
    return ns1 + '/' + ns2

def generate_launch_description():
    ns_param = 'ns'
    arm_id_1_param = "arm_id_1"
    arm_id_2_param = "arm_id_2"
    initial_positions_1_param = 'initial_positions_1'
    initial_positions_2_param = 'initial_positions_2'
    arm_x_1_param = 'arm_x_1'
    arm_y_1_param = 'arm_y_1'
    arm_z_1_param = 'arm_z_1'
    arm_yaw_1_param = 'arm_yaw_1'
    arm_x_2_param = 'arm_x_2'
    arm_y_2_param = 'arm_y_2'
    arm_z_2_param = 'arm_z_2'
    arm_yaw_2_param = 'arm_yaw_2'
    scene_xml_param = 'scene_xml'
    mujoco_plugin_config_param = 'mujoco_plugin_config'
    use_rviz_param = 'use_rviz'
    use_sim_time_param = 'use_sim_time'
    headless_param = 'headless'
    no_render_param = 'no_render'
    unpause_param = 'unpause'

    ns = LaunchConfiguration(ns_param)
    arm_id_1 = LaunchConfiguration(arm_id_1_param)
    arm_id_2 = LaunchConfiguration(arm_id_2_param)
    initial_positions_1 = LaunchConfiguration(initial_positions_1_param)
    initial_positions_2 = LaunchConfiguration(initial_positions_2_param)
    arm_x_1 = LaunchConfiguration(arm_x_1_param)
    arm_y_1 = LaunchConfiguration(arm_y_1_param)
    arm_z_1 = LaunchConfiguration(arm_z_1_param)
    arm_yaw_1 = LaunchConfiguration(arm_yaw_1_param)
    arm_x_2 = LaunchConfiguration(arm_x_2_param)
    arm_y_2 = LaunchConfiguration(arm_y_2_param)
    arm_z_2 = LaunchConfiguration(arm_z_2_param)
    arm_yaw_2 = LaunchConfiguration(arm_yaw_2_param)
    scene_xml = LaunchConfiguration(scene_xml_param)
    mujoco_plugin_config = LaunchConfiguration(mujoco_plugin_config_param)
    use_rviz = LaunchConfiguration(use_rviz_param)
    use_sim_time = LaunchConfiguration(use_sim_time_param)
    headless = LaunchConfiguration(headless_param)
    no_render = LaunchConfiguration(no_render_param)
    unpause = LaunchConfiguration(unpause_param)

    # Fixed variables
    load_gripper = True # We make gripper a fixed variable, mainly because parsing the argument 
                        # within generate_launch_description is a fairly unintuitive process, 
                        # and it's not worth doing just for a single boolean.
                        
    if(load_gripper): # mujoco scene file must be manually adjusted since there's no way to pass parameters
        default_scene_file = 'dual_scene.xml'
    else:
        default_scene_file = 'dual_scene_ng.xml'
    franka_xacro_file = os.path.join(get_package_share_directory('franka_description'), 'robots', 'sim',
                                     "dual_panda_arm_sim.urdf.xacro")
    default_xml_file = os.path.join(
        get_package_share_directory('franka_description'),
        'mujoco',
        'franka',
        default_scene_file,
    )
    default_mjros_config_file = os.path.join(
        get_package_share_directory('franka_bringup'),
        'config',
        'sim',
        'dual_sim_controllers.yaml',
    )
    franka_bringup_path = get_package_share_directory('franka_bringup')
    # Robot state publisher setup
    robot_description = Command(
        [FindExecutable(name='xacro'), ' ', franka_xacro_file, 
            ' arm_id_1:=', arm_id_1, 
            ' arm_id_2:=', arm_id_2,
            ' hand_1:=', str(load_gripper).lower(),
            ' hand_2:=', str(load_gripper).lower(),
            ' initial_positions_1:=', initial_positions_1,
            ' initial_positions_2:=', initial_positions_2,
            ' arm_x_1:=', arm_x_1,
            ' arm_y_1:=', arm_y_1,
            ' arm_z_1:=', arm_z_1,
            ' arm_yaw_1:=', arm_yaw_1,
            ' arm_x_2:=', arm_x_2,
            ' arm_y_2:=', arm_y_2,
            ' arm_z_2:=', arm_z_2,
            ' arm_yaw_2:=', arm_yaw_2])

    params = {'robot_description': robot_description}
    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[params, {'use_sim_time': use_sim_time}],
    )

    # Others
    rviz_file = os.path.join(get_package_share_directory('franka_description'), 'rviz',
                             'visualize_dual_franka.rviz')

    def spawner_args(controller_name):
        return [
            controller_name,
            '-c',
            'controller_manager',
            '--param-file',
            mujoco_plugin_config,
        ]
    

    return LaunchDescription([
        # Launch args
        DeclareLaunchArgument(
            ns_param,
            default_value='',
            description='Namespace for the entire MuJoCo dual-arm stack.',
        ),
        DeclareLaunchArgument(
            use_rviz_param,
            default_value='false',
            description='Visualize the robot in Rviz'),
        DeclareLaunchArgument(
            scene_xml_param,
            default_value=default_xml_file,
            description='MuJoCo scene xml for this dual-arm simulation instance.'),
        DeclareLaunchArgument(
            mujoco_plugin_config_param,
            default_value=default_mjros_config_file,
            description='ROS 2 parameter file used by mujoco_ros and controller_manager.'),
        DeclareLaunchArgument(
            use_sim_time_param,
            default_value='false',
            description='Publish and consume simulation time from /clock. Keep this false when combining multiple MuJoCo instances.'),
        DeclareLaunchArgument(
            headless_param,
            default_value='true',
            description='Run MuJoCo without the GLFW viewer window.'),
        DeclareLaunchArgument(
            no_render_param,
            default_value='false',
            description='Disable MuJoCo on-screen and offscreen rendering.'),
        DeclareLaunchArgument(
            unpause_param,
            default_value='true',
            description='Start MuJoCo unpaused so controllers receive advancing sim time.'),
        DeclareLaunchArgument(
            arm_id_1_param,
            default_value='panda01',
            description='Unique name of robot 1.'
        ),
        DeclareLaunchArgument(
            arm_id_2_param,
            default_value='panda02',
            description='Unique name of robot 2.'
        ),
        DeclareLaunchArgument(
            initial_positions_1_param,
            default_value='"0.0 -0.785 0.0 -2.356 0.0 1.571 0.785"',
            description='Initial joint positions of robot 1. Must be enclosed in quotes, and in pure number.'
                        'Defaults to the "communication_test" pose.'),
        DeclareLaunchArgument(
            initial_positions_2_param,
            default_value='"0.0 -0.785 0.0 -2.356 0.0 1.571 0.785"',
            description='Initial joint positions of robot 2. Must be enclosed in quotes, and in pure number.'
                        'Defaults to the "communication_test" pose.'),
        DeclareLaunchArgument(arm_x_1_param, default_value='0', description='Base x of robot 1 in the MuJoCo world frame.'),
        DeclareLaunchArgument(arm_y_1_param, default_value='0.26', description='Base y of robot 1 in the MuJoCo world frame.'),
        DeclareLaunchArgument(arm_z_1_param, default_value='0', description='Base z of robot 1 in the MuJoCo world frame.'),
        DeclareLaunchArgument(arm_yaw_1_param, default_value='0', description='Base yaw of robot 1 in the MuJoCo world frame.'),
        DeclareLaunchArgument(arm_x_2_param, default_value='0', description='Base x of robot 2 in the MuJoCo world frame.'),
        DeclareLaunchArgument(arm_y_2_param, default_value='-0.26', description='Base y of robot 2 in the MuJoCo world frame.'),
        DeclareLaunchArgument(arm_z_2_param, default_value='0', description='Base z of robot 2 in the MuJoCo world frame.'),
        DeclareLaunchArgument(arm_yaw_2_param, default_value='0', description='Base yaw of robot 2 in the MuJoCo world frame.'),

        GroupAction([
            PushRosNamespace(ns),
            IncludeLaunchDescription(
                FrontendLaunchDescriptionSource(franka_bringup_path + '/launch/sim/launch_mujoco_ros_server.launch'),
                launch_arguments={
                    'use_sim_time': use_sim_time,
                    'modelfile': scene_xml,
                    'verbose': "true",
                    'ns': ns,
                    'headless': headless,
                    'no_render': no_render,
                    'unpause': unpause,
                    'mujoco_plugin_config': mujoco_plugin_config
                    # 'mujoco_plugin_config': os.path.join(mjr2_control_path, 'example', 'ros2_control_plugins_example.yaml')

                }.items()
            ),

            # Miscellaneous
            node_robot_state_publisher,
            Node( # RVIZ dependency
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args('joint_state_broadcaster'),
                output='screen',
            ),
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args('sim_multi_mode_controller'),
                output='screen',
            ),
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args('franka_left_robot_state_broadcaster'),
                output='screen',
            ),
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args('franka_right_robot_state_broadcaster'),
                output='screen',
            ),
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args('franka_left_robot_model_broadcaster'),
                output='screen',
            ),
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args('franka_right_robot_model_broadcaster'),
                output='screen',
            ),
            Node(package='rviz2',
                 executable='rviz2',
                 name='rviz2',
                 arguments=['--display-config', rviz_file],
                 condition=IfCondition(use_rviz)
                 ),
        ])

    ])
