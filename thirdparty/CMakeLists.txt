cmake_minimum_required(VERSION 3.2)
project(cpp_third)
set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories("../include")

# include_directories("../../thirdparty/rocks-v6.13.3/include")
# link_directories("../../thirdparty/rocks-v6.13.3/lib")
# add_executable(rocksdb_test1 rocksdb_test1.cpp)
# target_link_libraries(rocksdb_test1 pthread dl z bz2 lz4 rocksdb)
# add_executable(rocksdb_test2 rocksdb_test2.cpp)
# target_link_libraries(rocksdb_test2 pthread dl z bz2 lz4 rocksdb)

include_directories("/opt/rh/local/terarkdb-1.3.6/include")
link_directories("/opt/rh/local/lib")
link_directories("/opt/rh/local/terarkdb-1.3.6/lib")
add_executable(terarkdb_test1 terarkdb_test1.cpp)
target_link_libraries(terarkdb_test1 pthread dl terarkdb z bz2 lz4 zstd snappy)

