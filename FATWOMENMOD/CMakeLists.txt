cmake_minimum_required(VERSION 3.10)

project(fatwomenmod)

find_package(Geode REQUIRED)

geode_add_target(
    ${PROJECT_NAME}
    src/main.cpp
)

geode_finalize_target(${PROJECT_NAME})