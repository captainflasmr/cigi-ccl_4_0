cmake_minimum_required(VERSION 3.16)

project(AnimalWrapperProj VERSION 1.0 LANGUAGES CXX)

if ( MSVC )
  set(SWIG_DIR "C:/Users/jimbo/OneDrive/Documents/swig/swigwin-4.2.1/swigwin-4.2.1/Lib")
  set(SWIG_EXECUTABLE "C:/Users/jimbo/OneDrive/Documents/swig/swigwin-4.2.1/swigwin-4.2.1/swig.exe")
endif (MSVC)

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

set (CMAKE_SWIG_FLAGS "")

file(GLOB SOURCE_FILES
  "${CMAKE_SOURCE_DIR}/*.cpp")

add_executable(animal ${SOURCE_FILES})

set_property(SOURCE animal.i PROPERTY CPLUSPLUS ON)
set_source_files_properties(animal.i PROPERTIES SWIG_FLAGS "-includeall")

swig_add_library(animallib
  TYPE SHARED
  LANGUAGE CSharp
  SOURCES animal.i animal.cpp
  OUTPUT_DIR ${CMAKE_SOURCE_DIR}
  OUTFILE_DIR ${CMAKE_SOURCE_DIR}
  )

set_target_properties(animallib
    PROPERTIES
    # These copy animal.dll on Windows to directory
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}

    # This copies animal.so on Linux to directory
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}

    # Set address of C++ headers
    INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}
)
