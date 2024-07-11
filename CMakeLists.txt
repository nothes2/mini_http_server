cmake_minimum_required(VERSION 3.11)
project(MiniHttpServer)

set(CMAKE_C_STANDARD 11)

enable_testing()

include(FetchContent)

message(STATUS "Configuring Unity as a dependency")
FetchContent_Declare(
    Unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG        master
    SOURCE_DIR     ../lib/unity
)           

message(STATUS "Make Unity available")
FetchContent_MakeAvailable(Unity)

set(SOURCE_FILES ./test/tools.c)

include_directories(include ../lib/unity/src)

add_executable(MiniHttpServer src/main.c src/httpserver.c)
add_executable(runTests test/test.c)

target_link_libraries(runTests PRIVATE unity)

add_test(NAME test COMMAND runTests)