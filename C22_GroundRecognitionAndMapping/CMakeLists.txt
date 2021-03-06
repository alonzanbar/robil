cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
rosbuild_genmsg()
#uncomment if you have defined services
rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})

rosbuild_add_boost_directories()
find_package( PCL 1.5 REQUIRED )

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


rosbuild_add_library(pclPlane src/pclPlane.cpp)
rosbuild_add_library(MPlane src/MPlane.cpp)
rosbuild_add_library(MapSquare src/MapSquare.cpp)
target_link_libraries(MapSquare MPlane)
rosbuild_add_library(MapMatrix src/MapMatrix.cpp)
target_link_libraries(MapMatrix pclPlane MPlane MapSquare)
rosbuild_link_boost(MapMatrix thread)
rosbuild_add_executable(C22 src/C22_Node.cpp)
target_link_libraries(C22 MapMatrix ${PCL_LIBRARIES})
rosbuild_link_boost(C22 thread signals)
rosbuild_add_executable(C22Cheat src/C22_NodeCheat.cpp)
target_link_libraries(C22Cheat MapMatrix ${PCL_LIBRARIES})
rosbuild_link_boost(C22Cheat thread signals)
rosbuild_add_executable(C22_test src/C22_Test.cpp)
