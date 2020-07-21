cmake_minimum_required(VERSION 3.7)

# set(CMAKE_CXX_STANDARD 17)
project(hotdog_video_detector)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

find_package(OpenCV 4.1 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

# Find all executables
file(GLOB project_SRCS src/*.cpp) #src/*.h

# Add project executable
add_executable(hotdog_video_detector ${project_SRCS})
target_link_libraries(hotdog_video_detector ${OpenCV_LIBRARIES})
