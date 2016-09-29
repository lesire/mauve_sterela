# CMake file for reconfigure service
find_package(catkin COMPONENTS rtt_dynamic_reconfigure)
include_directories( ${catkin_INCLUDE_DIRS} )
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
orocos_plugin(SafePilot_reconfigure ${SRC})
add_dependencies(SafePilot_reconfigure sterela_gencfg)
target_link_libraries(SafePilot_reconfigure ${catkin_LIBRARIES})
    