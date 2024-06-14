cmake_minimum_required(VERSION 3.1)
project(CigiMiniHostCSharp LANGUAGES CSharp)

set(CMAKE_CSharp_COMPILER "C:/Program Files/dotnet/dotnet.exe")
enable_language(CSharp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# Specify the .NET framework to target
set(DOTNET_TARGET_FRAMEWORK "4.8")

include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}/../../include"
)

file(GLOB SOURCE_FILES
  "${CMAKE_SOURCE_DIR}/csharp/*.cs"
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cs")

if(WIN32)
  set(LIB_CCL "${CMAKE_CURRENT_SOURCE_DIR}/../../build/windows/debug/lib/Debug/ccl_dllD.lib")
endif()

set(LIB_FILES ${LIB_CCL})

add_executable(CigiMiniHostCSharp ${SOURCE_FILES})
add_dependencies(CigiMiniHostCSharp cigicl-shared)

# Specify the .NET framework
set_property(TARGET CigiMiniHostCSharp PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION ${DOTNET_TARGET_FRAMEWORK})
set_property(TARGET CigiMiniHostCSharp PROPERTY VS_DOTNET_REFERENCES "System" "System.Collections" "System.Net.Sockets" "System.IO" "System.Xml" "System.Threading.Tasks")
# Add the System.Net.Sockets package reference


if(MSVC)
  target_compile_options(CigiMiniHostCSharp PRIVATE /W4 /D_CRT_SECURE_NO_WARNINGS /MDd)
  target_link_libraries(CigiMiniHostCSharp ${LIB_FILES} ws2_32)
else()
  target_compile_options(CigiMiniHostCSharp PRIVATE -Wall -g)
  target_link_libraries(CigiMiniHostCSharp ${LIB_FILES})
endif()

set_target_properties("CigiMiniHostCSharp" PROPERTIES
  LINKER_LANGUAGE CSharp
)

INSTALL(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/MiniHost.def
  DESTINATION ${CMAKE_SOURCE_DIR}/build/windows/debug/bin/Debug)
