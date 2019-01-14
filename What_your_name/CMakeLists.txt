cmake_minimum_required(VERSION 3.0)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

project(name)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories( ${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIR})

add_executable(
    name
    main.cpp
    RendererText.cpp
)

target_link_libraries(name ${SDL2_LIBRARIES} SDL2_ttf)