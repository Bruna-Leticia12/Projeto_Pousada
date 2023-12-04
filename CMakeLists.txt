cmake_minimum_required(VERSION 3.26)
project(projetoHotel C)

set(CMAKE_C_STANDARD 11)

add_executable(projetoHotel main.c
        funcaoHotel.h
        funcaoHotel.c)
