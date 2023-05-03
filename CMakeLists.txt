cmake_minimum_required(VERSION 3.10)

project(md2a LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(md2a ${SOURCES})

