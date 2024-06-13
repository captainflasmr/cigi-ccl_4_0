cmake_minimum_required(VERSION 3.10)
project(tinyxml)

# Ensure compile_commands.json is always generated.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

option(DEBUG "Include debugging info" YES)
option(PROFILE "Include profiling info" NO)
option(TINYXML_USE_STL "Turn on STL support" YES)

set(DEBUG_FLAGS "-Wall -g -DDEBUG")
set(RELEASE_FLAGS "-Wall -Wno-unknown-pragmas -Wno-format -O3")

if(TINYXML_USE_STL)
  add_definitions(-DTIXML_USE_STL)
endif()

if(DEBUG)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${DEBUG_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DEBUG_FLAGS}")
else()
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${RELEASE_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${RELEASE_FLAGS}")
endif()

if(PROFILE)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg -O3")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg -O3")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
endif()

file(GLOB SOURCE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(xmltest ${SOURCE_FILES})
add_library(tinyxml STATIC ${SOURCE_FILES})
