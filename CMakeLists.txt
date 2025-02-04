cmake_minimum_required(VERSION 3.28)
project(chestRandomizer C)

set(CMAKE_C_STANDARD 11)

add_executable(chestRandomizer main.c
        settings.c
        settings.h)
