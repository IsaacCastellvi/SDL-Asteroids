cmake_minimum_required(VERSION 3.10)
project(SDL_Asteroids VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(Asteroids ${SOURCES})

target_include_directories(Asteroids PRIVATE include/ ${SDL2_INCLUDE_DIRS})

target_link_libraries(Asteroids ${SDL2_LIBRARIES})

if(WIN32)
    target_link_libraries(Asteroids SDL2main)
endif()