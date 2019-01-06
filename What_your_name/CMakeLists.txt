set(CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)
cmake_minimum_required(VERSION 3.0)
project(name)
find_package(SDL2 REQUIRED)

include_directories( ${SDL2_INCLUDE_DIRS})

add_executable(
    name
    main.cpp
    RenText.cpp
    WinDow.cpp
)

target_link_libraries(name ${SDL2_LIBRARIES} SDL2_ttf)