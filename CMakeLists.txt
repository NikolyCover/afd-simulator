cmake_minimum_required(VERSION 3.27)
project(afd_simulator C)

set(CMAKE_C_STANDARD 99)

add_executable(afd_simulator main.c
        service.c
        model.h
        controller.c
        controller.h
        service.h)
