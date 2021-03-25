cmake_minimum_required(VERSION 3.0.2)
project(ros_tutorials)

<<<<<<< HEAD
 add_compile_options(-std=c++11)
=======
add_compile_options(-std=c++11)
>>>>>>> 382c58c1f2e5e8517730a4c52f13b648350d9f80

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ros_tutorials
<<<<<<< HEAD
  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
=======
#  CATKIN_DEPENDS roscpp
  DEPENDS system_lib
>>>>>>> 382c58c1f2e5e8517730a4c52f13b648350d9f80
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
<<<<<<< HEAD

add_executable(${PROJECT_NAME}_node src/ros_tutorials_node.cpp)
add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})
=======
add_executable(ros_mt_node src/ros_mt_node.cpp)
add_dependencies(ros_mt_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_mt_node ${catkin_LIBRARIES})
>>>>>>> 382c58c1f2e5e8517730a4c52f13b648350d9f80
