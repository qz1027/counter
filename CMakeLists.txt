cmake_minimum_required(VERSION 3.0)

project(counter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main main.cpp src/calculate.cpp src/manageMent.cpp)