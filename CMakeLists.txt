cmake_minimum_required(VERSION 3.2)
project(arma_hack)

set(DCMAKE_C_COMPILER clang)
set(DCMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(arma_hack ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-sign-compare -Wreorder -Wunused-private-field -Wunused-function")

target_link_libraries(arma_hack netfilter_queue)