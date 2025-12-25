cmake_minimum_required(VERSION 3.15)
project(concurrency-primitives LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_library(concurrency-primitives INTERFACE)
target_include_directories(concurrency-primitives INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(test
  src/main.cpp
  # Tests
  tests/test_TestRunner.cpp
  tests/test_spinlockCPP11.cpp
)
target_link_libraries(test PRIVATE
  concurrency-primitives
  Threads::Threads
)

target_compile_features(test PRIVATE cxx_std_20)
