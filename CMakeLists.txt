cmake_minimum_required(VERSION 3.10)

project(HospitalAppointmentSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

file(GLOB_RECURSE CORE_SOURCES
    src/core/*.cpp
)

add_executable(app
    src/app/Main.cpp
    ${CORE_SOURCES}
)

enable_testing()

# =========================
# GoogleTest (FIXED)
# =========================
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCES
    tests/*.cpp
)

add_executable(runTests
    ${TEST_SOURCES}
    ${CORE_SOURCES}
)

target_link_libraries(runTests
    GTest::gtest
    GTest::gtest_main
    pthread
)

include(GoogleTest)
gtest_discover_tests(runTests)
