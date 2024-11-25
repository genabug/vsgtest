cmake_minimum_required(VERSION 3.13)

project(vsgtest LANGUAGES CXX)

enable_testing()

find_package(GTest QUIET)
if(NOT GTest_FOUND)
  set(GOOGLETEST_VERSION 1.15.2)
  message(STATUS "gtest not found, use project's copy '${GOOGLETEST_VERSION}'")
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  add_subdirectory(googletest-1.15.2)
endif()

include(CTest)
include(GoogleTest)

add_executable(${PROJECT_NAME} test.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)

gtest_discover_tests(${PROJECT_NAME})
