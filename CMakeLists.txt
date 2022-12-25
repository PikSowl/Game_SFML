cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Game_SFML)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")

add_executable("${PROJECT_NAME}" main.cpp
        inc/Drawer.hpp
        src/Drawer.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/Code/Libraries/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/Code/Libraries/SFML/include)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
