cmake_minimum_required(VERSION 2.9)
project(cpp11)

set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories("include")

add_executable(vector_test vector_test.cpp)
add_executable(list_test list_test.cpp)
add_executable(array_test array_test.cpp)
add_executable(forward_list_test forward_list_test.cpp)
add_executable(deque_test deque_test.cpp)
add_executable(stack_test stack_test.cpp)
add_executable(queue_test queue_test.cpp)
add_executable(priority_queue_test priority_queue_test.cpp)
add_executable(map_test map_test.cpp)
add_executable(set_test set_test.cpp)
add_executable(unordered_map_test unordered_map_test.cpp)
add_executable(unordered_set_test unordered_set_test.cpp)
add_executable(pair_test pair_test.cpp)

add_executable(template_test template_test.cpp)
add_executable(thread_test src/thread/thread_test.cpp)
add_executable(thread_test2 src/thread/thread_test2.cpp)
add_executable(atomic_test src/thread/atomic_test.cpp)
add_executable(future_test src/thread/future_test.cpp)
add_executable(future2_test src/thread/future2_test.cpp)
add_executable(mutex_test src/thread/mutex_test.cpp)
add_executable(cond_variable1 src/thread/cond_variable1.cpp)
add_executable(cond_variable2 src/thread/cond_variable2.cpp)
add_executable(cond_variable3 src/thread/cv_test.cpp)
add_executable(time_test1 src/common/time/time_test1.cpp)
add_executable(time_test2 src/common/time/time_test2.cpp)
add_executable(murmurhash src/murmurhash.cpp)

add_executable(uniqueptr_test src/smartptr/uniqueptr_test.cpp)

add_executable(cpp_test src/test/cpp_test.cpp)

include_directories("../thirdparty/rocks-v6.13.3/include")
link_directories("../thirdparty/rocks-v6.13.3/lib")
add_executable(rocksdb_test src/rocksdb_test.cpp)
target_link_libraries(rocksdb_test pthread dl z bz2 lz4 rocksdb)



