cmake_minimum_required(VERSION 3.8)
project(inspect_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)


set(THIS_PACKAGE_INCLUDE_DEPS
  rclcpp
  rclcpp_lifecycle
  rclcpp_action
  rclcpp_components
  pluginlib

  ins_msgs

  generate_parameter_library
)

foreach(dep ${THIS_PACKAGE_INCLUDE_DEPS})
  find_package(${dep} REQUIRED)
endforeach()

# Params library
generate_parameter_library(inspect_node_parameters
  "src/inspect_node_parameters.yaml"
)

add_library(inspect_node SHARED) 
target_sources(inspect_node 
  PRIVATE 
    src/inspect_node.cpp
    src/air_gauge_reader.cpp
)
target_compile_features(inspect_node PUBLIC c_std_11 cxx_std_20) # Require C99 and C++17
ament_target_dependencies(inspect_node
  ${THIS_PACKAGE_INCLUDE_DEPS}
)
target_include_directories(inspect_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(inspect_node
  $<BUILD_INTERFACE:inspect_node_parameters>
)
# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(inspect_node PRIVATE 
  "INSPECT_NODE_BUILDING_LIBRARY"
  # "DEBUG_CV"
  "CHAMFER_THRESHOLD=0.0128"
)

add_executable(inspect_node_main src/inspect_node_main.cpp)
target_link_libraries(inspect_node_main inspect_node)

install(
  DIRECTORY include/
  DESTINATION include
)
install(
  TARGETS inspect_node inspect_node_parameters
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
install(
  TARGETS inspect_node_main
  DESTINATION lib/${PROJECT_NAME}
)
install(
  DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


ament_export_include_directories(
  include
)
ament_export_libraries(
  inspect_node
)
ament_export_targets(
  export_${PROJECT_NAME}
)

ament_export_dependencies(
  ${THIS_PACKAGE_INCLUDE_DEPS}
)


ament_package()
