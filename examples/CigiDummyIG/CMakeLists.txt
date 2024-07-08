cmake_minimum_required(VERSION 3.10)
project(CigiDummyIG)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

option(DEBUG "Include debugging info" YES)
option(PROFILE "Include profiling info" NO)
option(TINYXML_USE_STL "Turn on STL support" YES)

include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}/../tinyxml"
  "${CMAKE_CURRENT_SOURCE_DIR}/../../include"
)

file(GLOB SOURCE_FILES
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

set(LIB_TINYXML "${CMAKE_SOURCE_DIR}/../tinyxml/build/libtinyuml.a")
set(LIB_CCL "${CMAKE_SOURCE_DIR}/../../build/lib/libccl_lib.a")

if(WIN32)
  set(LIB_TINYXML "${CMAKE_CURRENT_SOURCE_DIR}/../../build/windows/debug/lib/Debug/tinyxmlD.lib")
  set(LIB_CCL "${CMAKE_CURRENT_SOURCE_DIR}/../../build/windows/debug/lib/Debug/ccl_dllD.lib")
endif()

set(LIB_FILES ${LIB_TINYXML} ${LIB_CCL})

add_executable(CigiDummyIG ${SOURCE_FILES})
add_dependencies(CigiDummyIG tinyxml cigicl-shared)

if(MSVC)
  target_compile_options(CigiDummyIG PRIVATE /W4 /D_CRT_SECURE_NO_WARNINGS /MDd)
  target_link_libraries(CigiDummyIG ${LIB_FILES} ws2_32)
else()
  target_compile_options(CigiDummyIG PRIVATE -Wall -g)
  target_link_libraries(CigiDummyIG ${LIB_FILES})
endif()

if(PROFILE)
  if(MSVC)
    target_compile_options(CigiDummyIG PRIVATE /O2)
  else()
    target_compile_options(CigiDummyIG PRIVATE -pg -O3)
    target_link_options(CigiDummyIG PRIVATE -pg)
  endif()
endif()

INSTALL(FILES
   ${CMAKE_CURRENT_SOURCE_DIR}/CigiDummyIG.def
   DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../build/windows/debug/bin/Debug)
