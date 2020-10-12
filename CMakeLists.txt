cmake_minimum_required(VERSION 2.9)
project(cpp11)

set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")

add_executable(vector_test vector_test.cpp)
add_executable(list_test list_test.cpp)
add_executable(string_test string_test.cpp)
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

add_executable(template_test template_test.cpp)
add_executable(thread_test src/thread/thread_test.cpp)
add_executable(thread_test2 src/thread/thread_test2.cpp)
add_executable(atomic_test src/thread/atomic_test.cpp)
add_executable(mutex_test src/thread/mutex_test.cpp)
add_executable(cond_variable1 src/thread/cond_variable1.cpp)
add_executable(cond_variable2 src/thread/cond_variable2.cpp)
add_executable(cond_variable3 src/thread/cv_test.cpp)

add_executable(time_test src/common/time/time_test.cpp)

add_executable(murmurhash src/murmurhash.cpp)






