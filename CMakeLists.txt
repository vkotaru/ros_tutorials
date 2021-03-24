cmake_minimum_required(VERSION 3.0.2)
project(ros_tutorials)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ros_tutorials
#  CATKIN_DEPENDS roscpp
  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
add_executable(ros_mt_node src/ros_mt_node.cpp)
add_dependencies(ros_mt_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_mt_node ${catkin_LIBRARIES})