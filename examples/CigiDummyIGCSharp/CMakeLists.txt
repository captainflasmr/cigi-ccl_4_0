cmake_minimum_required(VERSION 3.1)
project(CigiDummyIGCSharp LANGUAGES CSharp)

enable_language(CSharp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# Specify the .NET framework to target
set(DOTNET_TARGET_FRAMEWORK "4.8")

include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}/../../include"
)

file(GLOB SOURCE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/../../csharp/*.cs"
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cs")

if(WIN32)
  set(LIB_CCL "${LIBRARY_OUTPUT_PATH}/ccl_dllD.lib")
endif()

set(LIB_FILES ${LIB_CCL})

add_executable(CigiDummyIGCSharp ${SOURCE_FILES})
add_dependencies(CigiDummyIGCSharp cigicl-shared)

# Specify the .NET framework
set_property(TARGET CigiDummyIGCSharp PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION ${DOTNET_TARGET_FRAMEWORK})
set_property(TARGET CigiDummyIGCSharp PROPERTY VS_DOTNET_REFERENCES "System" "System.Collections" "System.Net.Sockets" "System.IO" "System.Xml" "System.Threading.Tasks" "System.Runtime.InteropServices" "System.Text")

if(MSVC)
  target_compile_options(CigiDummyIGCSharp PRIVATE /W4 /D_CRT_SECURE_NO_WARNINGS /MDd)
  target_link_libraries(CigiDummyIGCSharp ${LIB_FILES} ws2_32)
else()
  target_compile_options(CigiDummyIGCSharp PRIVATE -Wall -g)
  target_link_libraries(CigiDummyIGCSharp ${LIB_FILES})
endif()

set_target_properties("CigiDummyIGCSharp" PROPERTIES
  LINKER_LANGUAGE CSharp
)

if(WIN32)
  INSTALL(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/MiniHost.def
    DESTINATION ${EXECUTABLE_OUTPUT_PATH}/Debug)
else()
  INSTALL(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/MiniHost.def
    DESTINATION ${EXECUTABLE_OUTPUT_PATH})
endif()
