cmake_minimum_required(VERSION 3.12)

project(demologger)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE LOGGER_SRC_FILES RELATIVE 
    ${CMAKE_SOURCE_DIR} "Logger/*.cpp"
)

include_directories(
    Logger
)

add_library(demologger SHARED ${LOGGER_SRC_FILES})

add_executable(main main.cpp)

target_link_libraries(main demologger)