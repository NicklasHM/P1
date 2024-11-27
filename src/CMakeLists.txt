include(FetchContent)
FetchContent_Declare(mtest
        URL https://github.com/MortenSchou/mtest/archive/refs/tags/v0.2.0.zip
        URL_HASH SHA256=bec1e90fb00a5bc155de12ed5ed39ea5d1a1b6fcfb6c80cce5ad3e38e360248c
)
FetchContent_MakeAvailable(mtest)


add_executable(P1 main.c
        functions/scan_nmrplade.c
        functions/scan_nmrplade.h
        functions/beregn_p_plads.c
        functions/beregn_p_plads.h)


add_executable(my_test
        test/test_functions.c
        test/test_functions.h)

target_link_libraries(my_test mtest)

discover_tests(my_test)