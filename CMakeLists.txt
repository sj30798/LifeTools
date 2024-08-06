cmake_minimum_required(VERSION 3.20)

project(LifeTools)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(FileReader)

add_executable(LifeTools main.cpp)

target_link_libraries(LifeTools PUBLIC FileReader)

target_include_directories(LifeTools
                            PUBLIC "${PROJECT_SOURCE_DIR}/FileReader")
                            