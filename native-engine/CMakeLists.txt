cmake_minimum_required(VERSION 3.20)
project(gfxboxsync_native_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(gfxboxsync_core
    src/audiomatcher.cpp
)

target_include_directories(gfxboxsync_core PUBLIC include)

option(GFXBOXSYNC_BUILD_TESTS "Build tests" ON)

if(GFXBOXSYNC_BUILD_TESTS)
    enable_testing()
    add_executable(gfxboxsync_core_tests tests/core_tests.cpp)
    target_link_libraries(gfxboxsync_core_tests PRIVATE gfxboxsync_core)
    add_test(NAME core_tests COMMAND gfxboxsync_core_tests)
endif()
