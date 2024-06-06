cmake_minimum_required(VERSION 3.10)
project(Example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
)

file(GLOB SOURCE_FILES
  "${CMAKE_SOURCE_DIR}/*.cpp")

add_executable(Example ${SOURCE_FILES})
