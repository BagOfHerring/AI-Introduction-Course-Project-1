cmake_minimum_required(VERSION 3.5)
project(controller)

set(CMAKE_CXX_STANDARD 17) # 指定使用 C++17 标准编译代码
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 强制要求使用指定的 C++ 标准（如 17）
set(CMAKE_CXX_EXTENSIONS OFF) # 禁用编译器的非标准扩展（如 GNU 扩展），只用纯标准 C++

# ##########
# # 找包  ##
# ##########
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  sensor_msgs
  trajectory_msgs # trajectory_msgs用于处理轨迹消息
  roslib # roslib用于ROS包的查找和依赖管理
  message_generation
  visualization_msgs # 新增：ssa_controller 订阅 MarkerArray

  cplus_dev
)

find_package(Eigen3 REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(OpenMP REQUIRED)

# 注册给ros 包
catkin_package(
  CATKIN_DEPENDS roscpp std_msgs geometry_msgs sensor_msgs trajectory_msgs message_runtime visualization_msgs cplus_dev
)

# 设置rust相关路径
set(RUST_TARGET_DIR "/home/robot-lab-user/yixing/drives/target") # ← 改成绝对路径

# set(RUST_CRATE_NAME "roplat_exrobot") # ← a
set(RUST_CRATE_NAME "franka_rust") # ← a

# 库文件（静态库）
set(RUST_LIB "${RUST_TARGET_DIR}/release/lib${RUST_CRATE_NAME}.a")

# ##########
# # 编译 ##
# ##########
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/controller

  # ${CMAKE_CURRENT_SOURCE_DIR}/include/Robot_classes
  # ${CMAKE_CURRENT_SOURCE_DIR}/include/utilities_function
  # ${CMAKE_CURRENT_SOURCE_DIR}/include/utilities_function/relu_smooth
  ${catkin_INCLUDE_DIRS}
)

# 声明一个 IMPORTED 的静态库目标，供 C++ 链接
add_library(${RUST_CRATE_NAME} STATIC IMPORTED GLOBAL)
set_target_properties(${RUST_CRATE_NAME} PROPERTIES
  IMPORTED_LOCATION "${RUST_LIB}"
)

file(GLOB_RECURSE ALL_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set(BUF_SRCS ${ALL_SRCS})
list(FILTER BUF_SRCS EXCLUDE REGEX ".*ssa_controller.*")
list(FILTER BUF_SRCS EXCLUDE REGEX ".*rust_controller.*")
list(FILTER BUF_SRCS EXCLUDE REGEX ".*gbp_mpc_controller.*")
set(SSA_SRCS ${ALL_SRCS})
list(FILTER SSA_SRCS EXCLUDE REGEX ".*controller_node.*")
list(FILTER SSA_SRCS EXCLUDE REGEX ".*rust_controller.*")
list(FILTER SSA_SRCS EXCLUDE REGEX ".*gbp_mpc_controller.*")
set(RUST_SRCS ${ALL_SRCS})
list(FILTER RUST_SRCS EXCLUDE REGEX ".*ssa_controller.*")
list(FILTER RUST_SRCS EXCLUDE REGEX ".*controller_node.*")
list(FILTER RUST_SRCS EXCLUDE REGEX ".*gbp_mpc_controller.*")

# 明确指定每个可执行文件的源，避免多个 main 冲突
add_executable(buffer_controller ${BUF_SRCS})
add_executable(ssa_controller ${SSA_SRCS})

# add_executable(rust_controller ${RUST_SRCS}) # disabled: rust controller not built in this configuration

# ##########
# # 链接 ##
# ##########

# 链接时包含 cplus_dev 导出的核心库（提供 RobotDescription 与距离计算实现）
target_link_libraries(buffer_controller
  ${catkin_LIBRARIES}

  # cplus_dev
  Eigen3::Eigen
  yaml-cpp
  OpenMP::OpenMP_CXX
)

target_link_libraries(ssa_controller
  ${catkin_LIBRARIES}

  # cplus_dev
  Eigen3::Eigen
  yaml-cpp
  OpenMP::OpenMP_CXX
)

add_executable(gbp_mpc_controller src/gbp_mpc_controller.cpp)
target_link_libraries(gbp_mpc_controller
  ${catkin_LIBRARIES}

  # cplus_dev
  Eigen3::Eigen
  yaml-cpp
  OpenMP::OpenMP_CXX
)

# target_link_libraries(rust_controller
# ${catkin_LIBRARIES}
# ${RUST_CRATE_NAME}
# Eigen3::Eigen
# yaml-cpp
# dl
# )