include(FetchContent)
FetchContent_Declare(mtest
        URL https://github.com/MortenSchou/mtest/archive/refs/tags/v0.2.0.zip
        URL_HASH SHA256=bec1e90fb00a5bc155de12ed5ed39ea5d1a1b6fcfb6c80cce5ad3e38e360248c
)
FetchContent_MakeAvailable(mtest)

# Put `FetchContent_MakeAvailable(mtest)`, `add_subdirectory(mtest)` or `find_package(mtest)` here.

add_executable(test_program
        test/test_functions.c
        functions/scan_nmrplade.c
        functions/scan_nmrplade.h
        functions/beregn_p_plads.c
        functions/beregn_p_plads.h
        functions/data.h)

target_link_libraries(test_program mtest)

# Automatically discover test cases in my_example_test and add them to CTest.
discover_tests(test_program)

add_executable(P1 main.c
        functions/scan_nmrplade.c
        functions/scan_nmrplade.h
        functions/beregn_p_plads.c
        functions/beregn_p_plads.h
        functions/simulering.c
        functions/simulering.h
        functions/data.h)



