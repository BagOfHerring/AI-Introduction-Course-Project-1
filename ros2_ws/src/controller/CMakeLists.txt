cmake_minimum_required(VERSION 3.8)
project(controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ##########
# # 找包  ##
# ##########
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)

find_package(cplus_dev REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(OpenMP REQUIRED)

# 设置rust相关路径
set(RUST_TARGET_DIR "/home/robot-lab-user/yixing/drives/target")
set(RUST_CRATE_NAME "franka_rust")

# 库文件（静态库）
set(RUST_LIB "${RUST_TARGET_DIR}/release/lib${RUST_CRATE_NAME}.a")

set(CONTROLLER_INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/controller
)

# ##########
# # 编译 ##
# ##########

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
add_executable(gbp_mpc_controller src/gbp_mpc_controller.cpp)

set(CONTROLLER_DEPS
  rclcpp
  std_msgs
  geometry_msgs
  sensor_msgs
  trajectory_msgs
  visualization_msgs
  cplus_dev
)

# ##########
# # 链接 ##
# ##########

target_include_directories(buffer_controller PRIVATE ${CONTROLLER_INCLUDE_DIRS})
ament_target_dependencies(buffer_controller ${CONTROLLER_DEPS})
target_link_libraries(buffer_controller
  Eigen3::Eigen
  yaml-cpp
  OpenMP::OpenMP_CXX
)

target_include_directories(ssa_controller PRIVATE ${CONTROLLER_INCLUDE_DIRS})
ament_target_dependencies(ssa_controller ${CONTROLLER_DEPS})
target_link_libraries(ssa_controller
  Eigen3::Eigen
  yaml-cpp
  OpenMP::OpenMP_CXX
)

target_include_directories(gbp_mpc_controller PRIVATE ${CONTROLLER_INCLUDE_DIRS})
ament_target_dependencies(gbp_mpc_controller ${CONTROLLER_DEPS})
target_link_libraries(gbp_mpc_controller
  Eigen3::Eigen
  yaml-cpp
  OpenMP::OpenMP_CXX
)

# ##########
# # Install ##
# ##########

install(TARGETS
  buffer_controller
  ssa_controller
  gbp_mpc_controller
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)

install(DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)

ament_package()
