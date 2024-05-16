cmake_minimum_required(VERSION 3.8)
project(pcl_processing)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(ament_cmake REQUIRED)
find_package(PCL REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcd_import src/0_table_scene.cpp)
target_link_libraries(pcd_import ${PCL_LIBRARIES})

add_executable(plane_cloud src/1_planner_cloud.cpp)
target_link_libraries(plane_cloud ${PCL_LIBRARIES})

add_executable(circular_cloud src/2_circular_cloud.cpp)
target_link_libraries(circular_cloud ${PCL_LIBRARIES})

add_executable(pcl_filter src/3_filtering.cpp)
target_link_libraries(pcl_filter ${PCL_LIBRARIES})

add_executable(kitti_voxel src/5_kitti_voxel.cpp)
ament_target_dependencies(kitti_voxel rclcpp sensor_msgs std_msgs pcl_conversions)
target_link_libraries(kitti_voxel ${PCL_LIBRARIES})

install(TARGETS
  kitti_voxel
  circular_cloud
  pcd_import
  plane_cloud
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY 

  launch
  rviz
  DESTINATION share/${PROJECT_NAME}/)

ament_package() 
