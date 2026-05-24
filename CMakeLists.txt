cmake_minimum_required(VERSION 3.10)
project(SDL_Asteroids VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(Asteroids ${SOURCES})

target_include_directories(Asteroids PRIVATE 
    include/ 
    ${SDL2_INCLUDE_DIRS} 
    ${SDL2_IMAGE_INCLUDE_DIRS}
)

target_link_libraries(Asteroids 
    ${SDL2_LIBRARIES} 
    ${SDL2_IMAGE_LIBRARIES}
    SDL2_image
)

# Copy assets folder to build directory
add_custom_command(TARGET Asteroids POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets
)

if(WIN32)
    target_link_libraries(Asteroids SDL2main)
endif()

#temp
target_compile_options(Asteroids PRIVATE -g)
