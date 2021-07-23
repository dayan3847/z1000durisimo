# cmake_minimum_required(VERSION <specify CMake version here>)
project(z1000durisimo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(z1000durisimo
        z1000durisimo.ino
        zGeneral.ino
        zSpeed.ino
        zThermistor.ino)
