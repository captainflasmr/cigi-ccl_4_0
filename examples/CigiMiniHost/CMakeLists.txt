cmake_minimum_required(VERSION 3.10)
project(CigiMiniHost)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

option(DEBUG "Include debugging info" YES)
option(TINYXML_USE_STL "Turn on STL support" YES)

include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}/../tinyxml"
  "${CMAKE_CURRENT_SOURCE_DIR}/../../include"
)

file(GLOB SOURCE_FILES
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

if(WIN32)
  set(LIB_TINYXML "${CMAKE_SOURCE_DIR}/build/windows/debug/lib/Debug/tinyxmlD.lib")
  set(LIB_CCL "${CMAKE_CURRENT_SOURCE_DIR}/../../build/windows/debug/lib/Debug/ccl_dllD.lib")
endif()

set(LIB_FILES ${LIB_TINYXML} ${LIB_CCL})

add_executable(CigiMiniHost ${SOURCE_FILES})
add_dependencies(CigiMiniHost tinyxml cigicl-shared)

if(MSVC)
  target_compile_options(CigiMiniHost PRIVATE /W4 /D_CRT_SECURE_NO_WARNINGS /MDd)
  target_link_libraries(CigiMiniHost ${LIB_FILES} ws2_32)
else()
  target_compile_options(CigiMiniHost PRIVATE -Wall -g)
  target_link_libraries(CigiMiniHost ${LIB_FILES})
endif()

INSTALL(FILES
   ${CMAKE_CURRENT_SOURCE_DIR}/MiniHost.def
   DESTINATION ${CMAKE_SOURCE_DIR}/build/windows/debug/bin/Debug)
