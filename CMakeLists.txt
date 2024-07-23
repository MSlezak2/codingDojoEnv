cmake_minimum_required(VERSION 3.14)
project(DummyProj)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(MAIN_PROGRAM_NAME run_program)
set(TEST_PROGRAM_NAME tests)

add_executable(
    ${MAIN_PROGRAM_NAME}
    src/main.cpp
    src/snail.cpp
)

add_executable(
  ${TEST_PROGRAM_NAME}
  test/tests.cpp
  src/snail.cpp
)

target_include_directories(
    ${MAIN_PROGRAM_NAME}
    PUBLIC
    src/include/
)

target_include_directories(
    ${TEST_PROGRAM_NAME}
    PUBLIC
    src/include/
)

target_link_libraries(
  ${TEST_PROGRAM_NAME}
  GTest::gtest_main
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(${TEST_PROGRAM_NAME})