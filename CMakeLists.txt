cmake_minimum_required(VERSION 3.22)

find_package(Eigen3 REQUIRED)
project(MySProject LANGUAGES C)

add_executable(sscanf src/mainscan.c src/sscanf.c) 
target_sources(sscanf PRIVATE src/sscanf.h)

target_link_libraries(sscanf m)