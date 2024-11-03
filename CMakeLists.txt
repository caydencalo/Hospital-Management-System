cmake_minimum_required(VERSION 3.26)
project(Hospital_Management_System_)

set(CMAKE_CXX_STANDARD 11)

add_executable(Hospital_Management_System_ main.cpp
        header.hpp
        SystemMenu.cpp
        PatientLoginData.hpp
        List.hpp
        Node.hpp
        PatientHealthInfo.hpp
        PatientHealthInfo.hpp)
