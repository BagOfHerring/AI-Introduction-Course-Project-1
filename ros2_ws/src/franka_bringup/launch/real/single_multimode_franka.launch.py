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
import tempfile
from copy import deepcopy
from pathlib import Path

import yaml
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction, OpaqueFunction
from launch.conditions import IfCondition, UnlessCondition
from launch.substitutions import Command, FindExecutable, LaunchConfiguration
from launch_ros.actions import Node, PushRosNamespace


class _NoAliasSafeDumper(yaml.SafeDumper):
    def ignore_aliases(self, data):
        return True


def _matches_node_key(key, node_name):
    return key == node_name or key.endswith('/' + node_name)


def _update_node_parameters(config, node_name, parameters):
    for key, value in config.items():
        if _matches_node_key(key, node_name):
            value.setdefault('ros__parameters', {}).update(parameters)


def _ensure_wildcard_node_keys(config):
    wildcard_entries = {}
    for key, value in config.items():
        if key.startswith('/**/'):
            continue
        wildcard_entries[f'/**/{key}'] = deepcopy(value)
    config.update(wildcard_entries)


def _ensure_namespaced_node_keys(config, namespace):
    if not namespace:
        return
    normalized_namespace = namespace.strip('/')
    namespaced_entries = {}
    for key, value in config.items():
        if key.startswith('/'):
            continue
        if key.startswith(f'/{normalized_namespace}/'):
            continue
        namespaced_entries[f'/{normalized_namespace}/{key}'] = deepcopy(value)
    config.update(namespaced_entries)


def _build_controller_config(template_path, arm_id, namespace):
    config = yaml.safe_load(Path(template_path).read_text(encoding='utf-8'))
    _update_node_parameters(config, 'franka_robot_state_broadcaster', {'arm_id': arm_id})
    _update_node_parameters(config, 'franka_robot_model_broadcaster', {'arm_id': arm_id})
    _update_node_parameters(config, 'multi_mode_controller', {
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
    _ensure_wildcard_node_keys(config)
    _ensure_namespaced_node_keys(config, namespace)
    return config


def _launch_setup(context):
    ns = LaunchConfiguration('ns').perform(context)
    arm_id = LaunchConfiguration('arm_id').perform(context)
    controller_template = LaunchConfiguration('controller_config').perform(context)

    franka_xacro_file = os.path.join(
        get_package_share_directory('franka_description'),
        'robots',
        'real',
        'panda_arm.urdf.xacro',
    )
    rviz_file = os.path.join(
        get_package_share_directory('franka_description'),
        'rviz',
        'visualize_franka.rviz',
    )

    runtime_dir = Path(tempfile.mkdtemp(prefix=f'single_real_multimode_{arm_id}_'))
    runtime_controller_config = runtime_dir / 'single_multimode.runtime.yaml'
    runtime_controller_config.write_text(
        yaml.dump(
            _build_controller_config(controller_template, arm_id, ns),
            Dumper=_NoAliasSafeDumper,
            sort_keys=False,
        ),
        encoding='utf-8',
    )

    robot_description = Command([
        FindExecutable(name='xacro'),
        ' ',
        franka_xacro_file,
        ' hand:=',
        LaunchConfiguration('load_gripper'),
        ' robot_ip:=',
        LaunchConfiguration('robot_ip'),
        ' arm_id:=',
        LaunchConfiguration('arm_id'),
        ' use_fake_hardware:=',
        LaunchConfiguration('use_fake_hardware'),
        ' fake_sensor_commands:=',
        LaunchConfiguration('fake_sensor_commands'),
    ])

    control_node = Node(
        package='franka_control2',
        executable='franka_control2_node',
        parameters=[{'robot_description': robot_description}, str(runtime_controller_config)],
        remappings=[('joint_states', 'franka/joint_states')],
        output={'stdout': 'screen', 'stderr': 'screen'},
    )

    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_description}],
    )

    def spawner_args(controller_name, controller_ros_args=None):
        controller_manager_name = f'/{ns}/controller_manager' if ns else 'controller_manager'
        args = [
            controller_name,
            '-c',
            controller_manager_name,
            '--param-file',
            str(runtime_controller_config),
        ]
        for ros_arg in controller_ros_args or []:
            args.extend(['--controller-ros-args', ros_arg])
        return args

    return [
        GroupAction([
            PushRosNamespace(ns),
            control_node,
            robot_state_publisher,
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
                arguments=spawner_args('multi_mode_controller'),
                output='screen',
                condition=UnlessCondition(LaunchConfiguration('use_fake_hardware')),
            ),
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args('franka_robot_state_broadcaster'),
                output='screen',
                condition=UnlessCondition(LaunchConfiguration('use_fake_hardware')),
            ),
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=spawner_args('franka_robot_model_broadcaster'),
                output='screen',
                condition=UnlessCondition(LaunchConfiguration('use_fake_hardware')),
            ),
            Node(
                package='rviz2',
                executable='rviz2',
                name='rviz2',
                arguments=['--display-config', rviz_file],
                condition=IfCondition(LaunchConfiguration('use_rviz')),
            ),
        ])
    ]


def generate_launch_description():
    default_controller_config = os.path.join(
        get_package_share_directory('franka_bringup'),
        'config',
        'real',
        'single_multimode.yaml',
    )
    return LaunchDescription([
        DeclareLaunchArgument(
            'ns',
            default_value='',
            description='Namespace for the single-arm real or fake-real stack.',
        ),
        DeclareLaunchArgument(
            'arm_id',
            default_value='panda01',
            description='Robot arm identifier used for joints, topics, and controller resources.',
        ),
        DeclareLaunchArgument(
            'robot_ip',
            default_value='',
            description='Hostname or IP address of the robot.',
        ),
        DeclareLaunchArgument(
            'controller_config',
            default_value=default_controller_config,
            description='Controller YAML template for the single-arm real multimode stack.',
        ),
        DeclareLaunchArgument(
            'load_gripper',
            default_value='false',
            description='Load a Franka gripper model in the robot description.',
        ),
        DeclareLaunchArgument(
            'use_fake_hardware',
            default_value='false',
            description='Use fake hardware for the real-arm stack.',
        ),
        DeclareLaunchArgument(
            'fake_sensor_commands',
            default_value='false',
            description='Enable fake sensor commands when use_fake_hardware is true.',
        ),
        DeclareLaunchArgument(
            'use_rviz',
            default_value='false',
            description='Visualize this backend in RViz.',
        ),
        OpaqueFunction(function=_launch_setup),
    ])
