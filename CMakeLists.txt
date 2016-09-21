cmake_minimum_required(VERSION 3.5)
project(LivedFromBirthDay)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp)
add_executable(LivedFromBirthDay ${SOURCE_FILES})