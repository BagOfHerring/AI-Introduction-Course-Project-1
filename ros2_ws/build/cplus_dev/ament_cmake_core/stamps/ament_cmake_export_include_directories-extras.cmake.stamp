# generated from ament_cmake_export_include_directories/cmake/ament_cmake_export_include_directories-extras.cmake.in

set(_exported_include_dirs "${cplus_dev_DIR}/../../../include;${cplus_dev_DIR}/../../../include/GBP_classes;${cplus_dev_DIR}/../../../include/GBP_classes/graph_env_message;${cplus_dev_DIR}/../../../include/GBP_classes/factor_node;${cplus_dev_DIR}/../../../include/GBP_classes/value_node;${cplus_dev_DIR}/../../../include/GBP_classes/task_classes;${cplus_dev_DIR}/../../../include/Robot_classes;${cplus_dev_DIR}/../../../include/utilities_function;${cplus_dev_DIR}/../../../include/utilities_function/relu_smooth;${cplus_dev_DIR}/../../../include/other_packages/yaml")

# append include directories to cplus_dev_INCLUDE_DIRS
# warn about not existing paths
if(NOT _exported_include_dirs STREQUAL "")
  find_package(ament_cmake_core QUIET REQUIRED)
  foreach(_exported_include_dir ${_exported_include_dirs})
    if(NOT IS_DIRECTORY "${_exported_include_dir}")
      message(WARNING "Package 'cplus_dev' exports the include directory '${_exported_include_dir}' which doesn't exist")
    endif()
    normalize_path(_exported_include_dir "${_exported_include_dir}")
    list(APPEND cplus_dev_INCLUDE_DIRS "${_exported_include_dir}")
  endforeach()
endif()
