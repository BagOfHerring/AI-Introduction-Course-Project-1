import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/herring/rzddzy/ros2_ws/install/franka_ik_py'
