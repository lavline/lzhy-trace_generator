cmake_minimum_required(VERSION 3.11)
project(gen_trace)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
#find_package(Threads REQUIRED)

file(GLOB_RECURSE SRC_LIST "src/*.cpp" "src/*.h")
add_executable(gen_trace ${SRC_LIST})