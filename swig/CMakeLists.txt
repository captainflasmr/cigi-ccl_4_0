cmake_minimum_required(VERSION 3.29)
project(Example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE CCL_PUBLIC_HDRS "${CMAKE_SOURCE_DIR}/include/*.h")
file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/*.cpp")

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

set (CMAKE_SWIG_FLAGS "")

set_property(SOURCE example.i PROPERTY CPLUSPLUS ON)

set(INTERFACE_FILE_TEMPLATE "${CMAKE_SOURCE_DIR}/example.i.in")
set(INTERFACE_FILE "${CMAKE_SOURCE_DIR}/example.i")

file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/include/*.h")

set(INCLUDE_DIRECTIVES "")
set(INCLUDE_SWIG_DIRECTIVES "")
foreach(HEADER ${HEADER_FILES})
  get_filename_component(DIR_PATH ${HEADER} DIRECTORY)
  include_directories(${DIR_PATH})
  string(APPEND INCLUDE_DIRECTIVES "#include \"${HEADER}\"\n")
  string(APPEND INCLUDE_SWIG_DIRECTIVES "%include \"${HEADER}\"\n")
endforeach()

# Configure the .i file with dynamic includes
# configure_file(${INTERFACE_FILE_TEMPLATE} ${INTERFACE_FILE})

swig_add_library(examplelib
  TYPE SHARED
  LANGUAGE CSharp
  SOURCES example.i
  OUTPUT_DIR ${CMAKE_SOURCE_DIR}
  OUTFILE_DIR ${CMAKE_SOURCE_DIR}
  )

# add_library(examplelib
#   SHARED
#   ${SOURCE_FILES}
# )

# add_executable(Example ${SOURCE_FILES})
