cmake_minimum_required(VERSION 3.20)
project(CppDemo)

set(CMAKE_CXX_STANDARD 20)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)

set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d")

set_target_properties(${TARGET_NAME} PROPERTIES RELEASE_POSTFIX "_r")

include_directories(
        CppDemo/include
        )

#add_executable(CppDemo main.cpp 并发编程/condition_variable/条件变量simple.cpp)
#
#add_executable(vector vector/vector.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(vector_operate vector/vector_operate.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(exception try-catch/exception.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(try_catch try-catch/try_catch.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(time_mutex 并发编程/线程基础/time_mutex.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(swap 并发编程/线程基础/swap.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(mutex 并发编程/线程基础/mutex.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(lock_guard 并发编程/线程基础/lock_guard.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(jthreead 并发编程/线程基础/jthreead.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(base_thread 并发编程/线程基础/base_thread.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(reference ref/reference.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(smart_ptr ptr/smart_ptr.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(file file/file.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(virtual virtual/virtual.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(template template/template.cpp 并发编程/condition_variable/条件变量simple.cpp)
#add_executable(string_test string/string_test.cpp 并发编程/condition_variable/条件变量simple.cpp)