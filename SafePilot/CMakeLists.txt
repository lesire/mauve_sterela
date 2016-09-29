# Find OROCOS
if (NOT DEFINED OROCOS-RTT_FOUND)
  find_package(OROCOS-RTT REQUIRED ${RTT_HINTS})
  include(${OROCOS-RTT_USE_FILE_PATH}/UseOROCOS-RTT.cmake)
endif()
# Component
orocos_component( sterela-SafePilot SafePilot-component.cpp)
target_link_libraries(sterela-SafePilot ${catkin_LIBRARIES}
    ${USE_OROCOS_LIBRARIES} ${DEPS_LIBRARIES})
if( TARGET sterela-codels )
  target_link_libraries(sterela-SafePilot 
    sterela-codels sterela-lttng)
endif() 
orocos_install_headers( SafePilot-component.hpp
  DIRECTORY include/sterela)
orocos_generate_package( INCLUDE_DIRS include )
# Reconfigure service
add_subdirectory(reconfigure)