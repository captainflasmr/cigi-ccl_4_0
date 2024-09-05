cmake_minimum_required(VERSION 3.10)
project(Kermit)

enable_language(CSharp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

include_directories (
	"${CMAKE_SOURCE_DIR}/../animal"
)

file(GLOB SOURCE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cs"
  "${CMAKE_CURRENT_SOURCE_DIR}/../animal/*.cs"
)

set(LIBS "${CMAKE_SOURCE_DIR}/../animal/build/animallib.a")

if(WIN32)
  set(LIBS "${CMAKE_SOURCE_DIR}/../animal/animallib.dll")
endif()

set(LIB_FILES
  "${LIBS}"
)

add_executable(kermit ${SOURCE_FILES})

if(MSVC)
  target_compile_options(kermit PRIVATE /W4 /D_CRT_SECURE_NO_WARNINGS /MDd)
  target_link_libraries(kermit ${LIB_FILES})
else()
  target_compile_options(kermit PRIVATE -Wall -g)
  target_link_libraries(kermit ${LIB_FILES} -lpthread)
endif()

set_target_properties(kermit
PROPERTIES
LINKER_LANGUAGE CSharp)
