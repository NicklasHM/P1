cmake_minimum_required(VERSION 3.29)
project(P1 C)

set(CMAKE_C_STANDARD 99)

add_executable(P1 main.c
                scan_nmrplade.c
                scan_nmrplade.h
                beregn_p_plads.c
                beregn_p_plads.h)


