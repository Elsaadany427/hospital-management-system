cmake_minimum_required(VERSION 3.23)
project(hospital_management_system)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(hospital_management_system
        include/H00_00_GLOBAL.h
        include/H01_01_PERSON.h
        include/H02_02_ADDRESS.h
        include/H03_03_DOCTOR.h
        include/H04_04_HOSPITAL.h
        src/H00_00_GLOBAL.cpp
        src/H01_01_PERSON.cpp
        src/H02_02_ADDRESS.cpp
        src/H03_03_DOCTOR.cpp
        src/H04_04_HOSPITAL.cpp
        main.cpp)
