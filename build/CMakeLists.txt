cmake_minimum_required(VERSION 3.21)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(SFML_snake)

file(GLOB SOURCES ../src/*.cpp)  

add_executable(SFML_snake ${SOURCES})

target_include_directories(SFML_snake PUBLIC ../include)
target_link_libraries(SFML_snake -L sfml/lib -lsfml-graphics -lsfml-window -lsfml-system)
