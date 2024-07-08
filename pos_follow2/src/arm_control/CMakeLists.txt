cmake_minimum_required(VERSION 3.0.2)
project(arm_control)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CURSES_NEED_NCURSES TRUE)
find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  geometry_msgs
  roscpp
  rospy
  std_msgs
  tf
  message_generation
  message_runtime
  kdl_parser
)

add_message_files(
  FILES
  PosCmd.msg
  JointControl.msg 
  JointInformation.msg 
  ChassisCtrl.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs#   std_msgs
  # arx
)

generate_dynamic_reconfigure_options(
  cfg/reconfig.cfg
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
)

catkin_package(
 INCLUDE_DIRS include
 CATKIN_DEPENDS dynamic_reconfigure geometry_msgs roscpp rospy std_msgs tf #message_generation message_runtime
 CATKIN_DEPENDS kdl_parser
)

include_directories(
include
  ${catkin_INCLUDE_DIRS}
  ${roscpp_INCLUDE_DIRS}
)

add_library(arm_control
   SHARED
   src/App/arm_control.cpp


)

add_executable(arm_node4 src/arx.cpp)
add_dependencies(arm_node4 ${PROJECT_NAME}_gencfg)
# add_dependencies(arm_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS} ${PROJECT_NAME}_gencfg)







if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm.*|arm|aarch64")
    # Link libraries for ARM architecture
    target_link_libraries(arm_node4 
        ${catkin_LIBRARIES} 
        arm_control 
        # ${CMAKE_CURRENT_SOURCE_DIR}/src/arx_lib/libarm.so
        
        kdl_parser
    )
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "(x86_64)|(AMD64)|(^i686)")
    # Link libraries for x86 architecture
    target_link_libraries(arm_node4 
        ${catkin_LIBRARIES} 
        arm_control 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/arx_lib/libx86.so 

        kdl_parser
    )
endif()

install(TARGETS arm_node4
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(TARGETS arm_control
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

install(DIRECTORY
  ${CMAKE_CURRENT_SOURCE_DIR}/launch
  ${CMAKE_CURRENT_SOURCE_DIR}/models
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)