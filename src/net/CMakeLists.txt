
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}"
                   )
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../third-party/thrift-0.10.0/lib")

add_executable(client Client.cc)
add_executable()

target_link_libraries(client thrift pthread)


