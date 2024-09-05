cmake_minimum_required(VERSION 3.10)
project(AnimalWrapperPro)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(SWIG OFF)

if(SWIG)
  if (MSVC)
    set(SWIG_DIR "${CMAKE_SOURCE_DIR}/swig/swigwin-4.2.1/swigwin-4.2.1/Lib")
    set(SWIG_EXECUTABLE "${CMAKE_SOURCE_DIR}/swig/swigwin-4.2.1/swigwin-4.2.1/swig.exe")
  endif (MSVC)

  find_package(SWIG)
  include(${SWIG_USE_FILE})

  set(CMAKE_SWIG_FLAGS "")

  set_property(SOURCE animal.i PROPERTY CPLUSPLUS ON)
  set_source_files_properties(animal.i PROPERTIES SWIG_FLAGS "-includeall")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

file(GLOB SOURCE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(animal ${SOURCE_FILES})

IF(MSVC OR MINGW)
  add_library(animallib STATIC ${SOURCE_FILES})
else()
  if (SWIG)
    swig_add_library(animallib
      TYPE STATIC
      LANGUAGE CSharp
      SOURCES animal.i ${SOURCE_FILES}
      OUTPUT_DIR "${CMAKE_SOURCE_DIR}"
      OUTFILE_DIR "${CMAKE_SOURCE_DIR}")
  else()
    add_library(animallib STATIC ${SOURCE_FILES})
  endif()
endif()
