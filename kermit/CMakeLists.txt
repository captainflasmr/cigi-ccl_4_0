cmake_minimum_required(VERSION 3.10)
project(kermit)

set(CMAKE_CSharp_COMPILER "C:/Program Files/dotnet/dotnet.exe")
enable_language(CSharp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

include_directories(
  "${CMAKE_SOURCE_DIR}/../animal"
)

file(GLOB SOURCE_FILES
  "${CMAKE_SOURCE_DIR}/*.cs"
  "${CMAKE_SOURCE_DIR}/../animal/*.cs"
)

set(LIB "${CMAKE_SOURCE_DIR}/../animal/animal.so")

if(WIN32)
  set(LIB "${CMAKE_SOURCE_DIR}/../animal/animallib.dll")
endif()

set(LIB_FILES ${LIB})

add_executable(kermit ${SOURCE_FILES})

if(MSVC)
  target_compile_options(kermit PRIVATE /W4 /D_CRT_SECURE_NO_WARNINGS /MDd)
  target_link_libraries(kermit ${LIB_FILES} ws2_32)
else()
  target_compile_options(kermit PRIVATE -Wall -g)
  target_link_libraries(kermit ${LIB_FILES})
endif()

set_target_properties("kermit" PROPERTIES
    LINKER_LANGUAGE CSharp
)
