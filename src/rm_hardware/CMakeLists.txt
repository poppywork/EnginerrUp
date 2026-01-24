cmake_minimum_required(VERSION 3.8)
project(rm_hardware)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(hardware_interface REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rmctrl_msgs REQUIRED)
#包含include目录
include_directories(include)

#将硬件接口的源文件编译成 ROS 2 可动态加载的共享库
add_library(
  ${PROJECT_NAME}
  SHARED
  src/engineer_hardware_interface.cpp
)

#指定的 ROS 2 依赖库（如 rclcpp、hardware_interface 等）链接到add_library编译的共享库 ${PROJECT_NAME} 上
ament_target_dependencies(${PROJECT_NAME} rclcpp rclcpp_lifecycle hardware_interface pluginlib rmctrl_msgs )

#ROS2插件开发的注册环节，将XML描述文件和共享库关联
pluginlib_export_plugin_description_file(hardware_interface engieer_hardware_interface.xml)

install(
  TARGETS ${PROJECT_NAME}
  DESTINATION lib
)

install(
  DIRECTORY include
  DESTINATION include
)

ament_export_libraries(
  ${PROJECT_NAME}
)

ament_export_dependencies(
  hardware_interface
  pluginlib
  rclcpp
  rclcpp_lifecycle
  rmctrl_msgs
)

ament_package()
