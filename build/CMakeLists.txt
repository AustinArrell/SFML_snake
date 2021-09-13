cmake_minimum_required(VERSION 3.21)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(SNEK)

file(GLOB SOURCES ../src/*.cpp)  

add_executable(SNEK ${SOURCES})

target_include_directories(SNEK PUBLIC ../include)
target_link_libraries(SNEK -L sfml/lib -lsfml-graphics -lsfml-window -lsfml-system)

