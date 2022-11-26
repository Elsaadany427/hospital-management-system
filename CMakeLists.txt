cmake_minimum_required(VERSION 3.23)
project(hospital_management_system)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(hospital_management_system
        include/H01_01_PERSON.h
        include/H02_02_ADDRESS.h
        src/H01_01_PERSON.cpp
        src/H02_02_ADDRESS.cpp
        main.cpp)
