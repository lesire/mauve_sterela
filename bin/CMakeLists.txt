
## CMake file to generate executables; adapt the commented lines to use
#
#file(GLOB SRC_FILES my_bin.cpp)
## if your executable uses ROS:
#find_package(catkin REQUIRED roscpp)
#add_executable( my_bin ${SRC_FILES} )
#install(TARGETS my_bin
#  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)
#target_link_libraries( my_bin ${catkin_LIBRARIES} )
#target_link_libraries( my_bin sterela-codels sterela-lttng )
