cmake_minimum_required(VERSION 3.20)
project(gfxboxsync_standalone LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../native-engine native-engine)

add_executable(gfxboxsync_standalone
    src/main.cpp
)

target_link_libraries(gfxboxsync_standalone PRIVATE gfxboxsync_core)
