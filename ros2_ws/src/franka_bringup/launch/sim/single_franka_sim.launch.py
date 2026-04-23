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

import math
import os
import tempfile
from pathlib import Path

import yaml
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction, IncludeLaunchDescription, OpaqueFunction
from launch.conditions import IfCondition
from launch.launch_description_sources import FrontendLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable, LaunchConfiguration
from launch_ros.actions import Node, PushRosNamespace


class _NoAliasSafeDumper(yaml.SafeDumper):
    def ignore_aliases(self, data):
        return True


def _matches_node_key(key, node_name):
    return key == node_name or key.endswith('/' + node_name)


def _rename_node_keys(config, old_name, new_name):
    renames = {}
    for key in list(config.keys()):
        if _matches_node_key(key, old_name):
            if key == old_name:
                renames[key] = new_name
            else:
                prefix, _, _ = key.rpartition('/')
                renames[key] = prefix + '/' + new_name
    for old_key, new_key in renames.items():
        if old_key == new_key:
            continue
        config[new_key] = config.pop(old_key)


def _update_node_parameters(config, node_name, parameters):
    for key, value in config.items():
        if _matches_node_key(key, node_name):
            value.setdefault('ros__parameters', {}).update(parameters)


def _update_controller_manager(config):
    for key, value in config.items():
        if _matches_node_key(key, 'controller_manager'):
            params = value.setdefault('ros__parameters', {})
            if 'multi_mode_controller' in params and 'sim_multi_mode_controller' not in params:
                params['sim_multi_mode_controller'] = params.pop('multi_mode_controller')


def _build_controller_config(template_path, arm_id):
    config = yaml.safe_load(Path(template_path).read_text(encoding='utf-8'))

    _rename_node_keys(config, 'multi_mode_controller', 'sim_multi_mode_controller')
    _update_controller_manager(config)
    _update_node_parameters(config, 'franka_robot_state_broadcaster', {
        'arm_id': arm_id,
        'frequency': 30,
    })
    _update_node_parameters(config, 'franka_robot_model_broadcaster', {
        'arm_id': arm_id,
        'frequency': 30,
    })
    _update_node_parameters(config, 'joint_impedance_example_controller', {'arm_id': arm_id})
    _update_node_parameters(config, 'cartesian_impedance_example_controller', {'arm_id': arm_id})
    _update_node_parameters(config, 'sim_multi_mode_controller', {
        'arm_count': 1,
        'arm_1': {'arm_id': arm_id},
        'controllers': ['panda_joint_impedance_controller', 'panda_cartesian_impedance_controller'],
        'resources': {
            'panda_joint_impedance_controller': [arm_id],
            'panda_cartesian_impedance_controller': [arm_id],
        },
        'start_controllers': {
            'names': ['panda_joint_impedance_controller'],
            'resources': {
                'panda_joint_impedance_controller': [arm_id],
            },
        },
    })
    return config


def _render_single_robot_xml(template_path, arm_id, arm_x, arm_y, arm_z, arm_yaw):
    robot_xml = Path(template_path).read_text(encoding='utf-8')
    yaw = float(arm_yaw)
    quat_w = math.cos(yaw / 2.0)
    quat_z = math.sin(yaw / 2.0)
    mesh_dir = Path(template_path).resolve().parent / 'assets'

    robot_xml = robot_xml.replace('{YOUR_NAME}', arm_id)
    robot_xml = robot_xml.replace('meshdir="assets"', f'meshdir="{mesh_dir}"', 1)
    robot_xml = robot_xml.replace(
        'pos="0 0 0" quat="0 0 0 1"',
        f'pos="{arm_x} {arm_y} {arm_z}" quat="{quat_w:.16g} 0 0 {quat_z:.16g}"',
        1,
    )
    return robot_xml


def _render_scene_xml(scene_template_path, robot_xml_filename):
    scene_xml = Path(scene_template_path).read_text(encoding='utf-8')
    replacements = (
        '<include file="panda.xml"/>',
        '<include file="panda_ng.xml"/>',
        '<include file="TEMPLATE_panda.xml"/>',
    )
    for include_line in replacements:
        if include_line in scene_xml:
            return scene_xml.replace(
                include_line,
                f'<include file="{robot_xml_filename}"/>',
                1,
            )
    return scene_xml


def _launch_setup(context):
    ns_param = 'ns'
    arm_id_param = 'arm_id'
    initial_positions_param = 'initial_positions'
    arm_x_param = 'arm_x'
    arm_y_param = 'arm_y'
    arm_z_param = 'arm_z'
    arm_yaw_param = 'arm_yaw'
    scene_xml_param = 'scene_xml'
    mujoco_plugin_config_param = 'mujoco_plugin_config'
    use_rviz_param = 'use_rviz'
    use_sim_time_param = 'use_sim_time'
    headless_param = 'headless'
    no_render_param = 'no_render'
    unpause_param = 'unpause'

    ns = LaunchConfiguration(ns_param).perform(context)
    arm_id = LaunchConfiguration(arm_id_param).perform(context)
    arm_x = LaunchConfiguration(arm_x_param).perform(context)
    arm_y = LaunchConfiguration(arm_y_param).perform(context)
    arm_z = LaunchConfiguration(arm_z_param).perform(context)
    arm_yaw = LaunchConfiguration(arm_yaw_param).perform(context)
    scene_xml_template = LaunchConfiguration(scene_xml_param).perform(context)
    controller_template = LaunchConfiguration(mujoco_plugin_config_param).perform(context)

    load_gripper = True
    franka_bringup_path = get_package_share_directory('franka_bringup')
    franka_xacro_file = os.path.join(
        get_package_share_directory('franka_description'),
        'robots',
        'sim',
        'panda_arm_sim.urdf.xacro',
    )
    mujoco_template_robot = os.path.join(
        get_package_share_directory('franka_description'),
        'mujoco',
        'franka',
        'TEMPLATE_panda.xml',
    )
    rviz_file = os.path.join(
        get_package_share_directory('franka_description'),
        'rviz',
        'visualize_franka.rviz',
    )

    runtime_dir = Path(tempfile.mkdtemp(prefix=f'single_franka_sim_{arm_id}_'))
    runtime_controller_config = runtime_dir / 'single_sim_controllers.runtime.yaml'
    runtime_controller_config.write_text(
        yaml.dump(
            _build_controller_config(controller_template, arm_id),
            Dumper=_NoAliasSafeDumper,
            sort_keys=False,
        ),
        encoding='utf-8',
    )

    runtime_scene_xml = scene_xml_template
    rendered_scene = _render_scene_xml(scene_xml_template, arm_id + '.xml')
    if rendered_scene != Path(scene_xml_template).read_text(encoding='utf-8'):
        runtime_robot_xml = runtime_dir / (arm_id + '.xml')
        runtime_scene_xml_path = runtime_dir / 'scene.xml'
        runtime_robot_xml.write_text(
            _render_single_robot_xml(mujoco_template_robot, arm_id, arm_x, arm_y, arm_z, arm_yaw),
            encoding='utf-8',
        )
        runtime_scene_xml_path.write_text(rendered_scene, encoding='utf-8')
        runtime_scene_xml = str(runtime_scene_xml_path)

    use_rviz = LaunchConfiguration(use_rviz_param)
    use_sim_time = LaunchConfiguration(use_sim_time_param)
    initial_positions = LaunchConfiguration(initial_positions_param)

    robot_description = Command([
        FindExecutable(name='xacro'),
        ' ',
        franka_xacro_file,
        ' arm_id:=',
        LaunchConfiguration(arm_id_param),
        ' hand:=',
        str(load_gripper).lower(),
        ' initial_positions:=',
        initial_positions,
        ' arm_x:=',
        LaunchConfiguration(arm_x_param),
        ' arm_y:=',
        LaunchConfiguration(arm_y_param),
        ' arm_z:=',
        LaunchConfiguration(arm_z_param),
        ' arm_yaw:=',
        LaunchConfiguration(arm_yaw_param),
    ])

    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_description}, {'use_sim_time': use_sim_time}],
    )

    def spawner_args(controller_name, controller_ros_args=None):
        args = [
            controller_name,
            '-c',
            'controller_manager',
            '--param-file',
            str(runtime_controller_config),
        ]
        for ros_arg in controller_ros_args or []:
            args.extend(['--controller-ros-args', ros_arg])
        return args

    return [
        GroupAction([
            PushRosNamespace(ns),
            IncludeLaunchDescription(
                FrontendLaunchDescriptionSource(
                    franka_bringup_path + '/launch/sim/launch_mujoco_ros_server.launch'
                ),
                launch_arguments={
                    'use_sim_time': use_sim_time,
                    'modelfile': runtime_scene_xml,
                    'verbose': 'true',
                    'ns': ns,
                    'headless': LaunchConfiguration(headless_param),
                    'no_render': LaunchConfiguration(no_render_param),
                    'unpause': LaunchConfiguration(unpause_param),
                    'mujoco_plugin_config': str(runtime_controller_config),
                }.items(),
            ),
            node_robot_state_publisher,
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args(
                    'joint_state_broadcaster',
                    [f'--ros-args --remap joint_states:=/{arm_id}/joint_states'],
                ),
                output='screen',
            ),
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args('panda_joint_trajectory_controller'),
                output='screen',
            ),
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args('franka_robot_state_broadcaster'),
                output='screen',
            ),
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args('franka_robot_model_broadcaster'),
                output='screen',
            ),
            Node(
                package='rviz2',
                executable='rviz2',
                name='rviz2',
                arguments=['--display-config', rviz_file],
                condition=IfCondition(use_rviz),
            ),
        ])
    ]


def generate_launch_description():
    ns_param = 'ns'
    arm_id_param = 'arm_id'
    initial_positions_param = 'initial_positions'
    arm_x_param = 'arm_x'
    arm_y_param = 'arm_y'
    arm_z_param = 'arm_z'
    arm_yaw_param = 'arm_yaw'
    scene_xml_param = 'scene_xml'
    mujoco_plugin_config_param = 'mujoco_plugin_config'
    use_rviz_param = 'use_rviz'
    use_sim_time_param = 'use_sim_time'
    headless_param = 'headless'
    no_render_param = 'no_render'
    unpause_param = 'unpause'

    default_scene_file = os.path.join(
        get_package_share_directory('franka_description'),
        'mujoco',
        'franka',
        'scene_with_workbench.xml',
    )
    default_mjros_config_file = os.path.join(
        get_package_share_directory('franka_bringup'),
        'config',
        'sim',
        'single_sim_controllers.yaml',
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            ns_param,
            default_value='',
            description='Namespace for the entire MuJoCo single-arm stack.',
        ),
        DeclareLaunchArgument(
            use_rviz_param,
            default_value='false',
            description='Visualize the robot in Rviz',
        ),
        DeclareLaunchArgument(
            scene_xml_param,
            default_value=default_scene_file,
            description='MuJoCo scene xml template for this single-arm simulation instance.',
        ),
        DeclareLaunchArgument(
            mujoco_plugin_config_param,
            default_value=default_mjros_config_file,
            description='ROS 2 parameter file template used by mujoco_ros and controller_manager.',
        ),
        DeclareLaunchArgument(
            use_sim_time_param,
            default_value='false',
            description='Publish and consume simulation time from /clock. Keep this false when combining multiple MuJoCo instances.',
        ),
        DeclareLaunchArgument(
            headless_param,
            default_value='true',
            description='Run MuJoCo without the GLFW viewer window.',
        ),
        DeclareLaunchArgument(
            no_render_param,
            default_value='false',
            description='Disable MuJoCo on-screen and offscreen rendering.',
        ),
        DeclareLaunchArgument(
            unpause_param,
            default_value='true',
            description='Start MuJoCo unpaused so controllers receive advancing sim time.',
        ),
        DeclareLaunchArgument(
            arm_id_param,
            default_value='panda',
            description='Unique name of the robot.',
        ),
        DeclareLaunchArgument(
            initial_positions_param,
            default_value='"0.0 -0.785 0.0 -2.356 0.0 1.571 0.785"',
            description='Initial joint positions of the robot. Must be enclosed in quotes, and in pure number. Defaults to the communication_test pose.',
        ),
        DeclareLaunchArgument(
            arm_x_param,
            default_value='0',
            description='Base x of the robot in the MuJoCo world frame.',
        ),
        DeclareLaunchArgument(
            arm_y_param,
            default_value='0',
            description='Base y of the robot in the MuJoCo world frame.',
        ),
        DeclareLaunchArgument(
            arm_z_param,
            default_value='0',
            description='Base z of the robot in the MuJoCo world frame.',
        ),
        DeclareLaunchArgument(
            arm_yaw_param,
            default_value='0',
            description='Base yaw of the robot in the MuJoCo world frame.',
        ),
        OpaqueFunction(function=_launch_setup),
    ])
