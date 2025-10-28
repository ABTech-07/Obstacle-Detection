cmake_minimum_required(VERSION 3.10)
project(PedestrianDetection)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(PedestrianDetection src/main.cpp)

target_link_libraries(PedestrianDetection ${OpenCV_LIBS})
