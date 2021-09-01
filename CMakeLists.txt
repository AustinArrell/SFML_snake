cmake_minimum_required(VERSION 3.16)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(SNEK)

file(GLOB SOURCES *.cpp)  

add_executable(SNEK ${SOURCES})

target_link_libraries(SNEK -L sfml/lib -lsfml-graphics -lsfml-window -lsfml-system)


