cmake_minimum_required(VERSION 3.21)
project(C7_SmartCalc_v1_0_0 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(C7_SmartCalc_v1_0_0
        src/listFunction.c
        src/main.c
#        src/templ.c
        src/parser.c
        src/supportFunction.c
        src/underfile.h
        src/validator.c)
