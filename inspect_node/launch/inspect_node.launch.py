'''
  Inspect node Launch File
  @Author: Pan
'''
from launch import LaunchDescription
from launch.substitutions import PathJoinSubstitution

from launch_ros.actions import Node

from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    '''
	Gpio Launch File
    '''
    config_file = PathJoinSubstitution(
        [FindPackageShare('inspect_node'), 'config', 'inspect_node.yaml'])
    # check existence of config file
    inspect_node = Node(
        package='inspect_node',
        executable='inspect_node_main',
        parameters=[config_file],
        output="both",
        arguments=[
            "--ros-args",
            "--log-level",
            "INFO",
            # "--log-level",
            # "inspect_node:=DEBUG",
            # "--log-level",
            # "modbus:=DEBUG",
            # "--log-level",
            # "cv:=DEBUG",
        ],
    )
    return LaunchDescription([inspect_node])
