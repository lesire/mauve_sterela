
cmake_minimum_required(VERSION 2.8)
project(sterela)
# Find CATKIN packages
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake" )
find_package(catkin REQUIRED mauve sensor_msgs geometry_msgs std_msgs roscpp)
include_directories(include ${catkin_INCLUDE_DIRS})
# options
add_definitions( -fPIC )
# C++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. If you need this feature, please use a different C++ compiler.")
endif()
set( DEPS_LIBRARIES )
set( DEPS_INCLUDES )
# LTTng
if ( USE_LTTNG )
  add_definitions( -DUSE_LTTNG )
endif()
# Codels librarry
file(GLOB_RECURSE CODELS_FILES src/codels/*.cpp)
file(GLOB_RECURSE C_CODELS_FILES src/codels/*.c)
add_library( sterela-codels STATIC ${CODELS_FILES} ${C_CODELS_FILES} )
target_link_libraries( sterela-codels ${catkin_LIBRARIES} ${DEPS_LIBRARIES} )
# Dynamic reconfigure generation
find_package(catkin REQUIRED dynamic_reconfigure)
file(GLOB CFG ${CMAKE_CURRENT_SOURCE_DIR}/cfg/*.cfg)
generate_dynamic_reconfigure_options(${CFG})
# Components
add_subdirectory( ObstacleDetector )
add_subdirectory( SafePilot )
add_subdirectory( LineGuidance )
# Tracing library
add_subdirectory( lttng )
# executables
add_subdirectory( bin )
# Copy models
file(GLOB MODELS ${CMAKE_CURRENT_SOURCE_DIR}/models/*)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CATKIN_PACKAGE_SHARE_DESTINATION}/models)
add_custom_target( sterela-models-copy )
add_library( sterela-models SHARED ${MODELS} )
set_target_properties(sterela-models PROPERTIES LINKER_LANGUAGE CXX)
add_dependencies( sterela-models sterela-models-copy )
foreach(model ${MODELS})
  add_custom_command(TARGET sterela-models-copy POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
      copy ${model} ${CMAKE_CURRENT_BINARY_DIR}/${CATKIN_PACKAGE_SHARE_DESTINATION}/models)
endforeach()
# Catkin Package
catkin_package(
  INCLUDE_DIRS include ${DEPS_INCLUDES}
  LIBRARIES sterela-models sterela-codels sterela-lttng
  CATKIN_DEPENDS sensor_msgs geometry_msgs std_msgs roscpp
)
# Install library headers
install(
  DIRECTORY include/sterela
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  PATTERN ".svn" EXCLUDE
)
# Install models
install(
  DIRECTORY models
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  PATTERN ".svn" EXCLUDE
)
# Env hook for MAUVE_MODELS
catkin_add_env_hooks(sterela-env
  SHELLS sh
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/env
)