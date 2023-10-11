cmake_minimum_required(VERSION 3.20)
project(PPP_code)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
include(testing.cmake)
include(gui.cmake)

include_directories(${CMAKE_SOURCE_DIR})  # 头文件包含可相对于根目录
if(MSVC)
  add_compile_options(/utf-8)
endif()

add_subdirectory(GUI)  # 作者提供的GUI库
file(GLOB CHAPTERS RELATIVE ${CMAKE_SOURCE_DIR} ch*)
foreach(c IN ITEMS ${CHAPTERS})
  add_subdirectory(${c})
endforeach()
