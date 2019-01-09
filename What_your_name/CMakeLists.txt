cmake_minimum_required(VERSION 3.0)
project(name)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories( ${SDL2_INCLUDE_DIRS})

add_executable(
    name
    main.cpp
    RendererText.cpp
)

target_link_libraries(name ${SDL2_LIBRARIES} SDL2_ttf)