cmake_minimum_required(VERSION 3.10)
project(CigiMiniHost)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

option(DEBUG "Include debugging info" YES)
option(PROFILE "Include profiling info" NO)
option(TINYXML_USE_STL "Turn on STL support" YES)

include_directories(
  "${CMAKE_SOURCE_DIR}/../tinyxml"
  "${CMAKE_SOURCE_DIR}/../../include"
)

file(GLOB SOURCE_FILES
     "${CMAKE_SOURCE_DIR}/*.cpp")

set(LIB_TINYXML "${CMAKE_SOURCE_DIR}/../tinyxml/build/libtinyuml.a")
set(LIB_CCL "${CMAKE_SOURCE_DIR}/../../build/lib/libccl_lib.a")

if(WIN32)
  set(LIB_TINYXML "${CMAKE_SOURCE_DIR}/../tinyxml/out/build/x64-debug/tinyuml.lib")
  set(LIB_CCL "${CMAKE_SOURCE_DIR}/../../out/build/x64-debug/lib/ccl_libD.lib")
endif()

set(LIB_FILES ${LIB_TINYXML} ${LIB_CCL})

add_executable(CigiMiniHost ${SOURCE_FILES})

if(MSVC)
  target_compile_options(CigiMiniHost PRIVATE /W4 /D_CRT_SECURE_NO_WARNINGS /MDd)
  target_link_libraries(CigiMiniHost ${LIB_FILES} ws2_32)
else()
  target_compile_options(CigiMiniHost PRIVATE -Wall -g)
  target_link_libraries(CigiMiniHost ${LIB_FILES})
endif()

if(PROFILE)
  if(MSVC)
    target_compile_options(CigiMiniHost PRIVATE /O2)
  else()
    target_compile_options(CigiMiniHost PRIVATE -pg -O3)
    target_link_options(CigiMiniHost PRIVATE -pg)
  endif()
endif()
