cmake_minimum_required(VERSION 3.21)
project(C7_SmartCalc_v1_0_0 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(C7_SmartCalc_v1_0_0
math/s21_abs.c	math/s21_fabs.c
math/s21_sin.c	math/s21_cos.c
math/s21_fmod.c	math/s21_tan.c
math/s21_pow.c	math/s21_asin.c
math/s21_exp.c	math/s21_acos.c
math/s21_log.c	math/s21_sqrt.c
math/s21_ceil.c	math/s21_floor.c
math/s21_atan.c	math/remove_circle.c
        src/forFunc.c
        src/printers.c
        src/priorityFunction.c
        src/listFunction.c
        src/main.c
#        src/templ.c
        src/parser.c
        src/supportFunction.c
        src/underfile.h
        src/validator.c)
