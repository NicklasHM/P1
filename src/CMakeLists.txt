add_executable(P1 main.c
        functions/scan_nmrplade.c
        functions/scan_nmrplade.h
        functions/beregn_p_plads.c
        functions/beregn_p_plads.h
        functions/simulering.c
        functions/simulering.h
        functions/data.h)


add_executable(my_test
        test/test_functions.c
        functions/scan_nmrplade.c
        functions/scan_nmrplade.h
        functions/beregn_p_plads.c
        functions/beregn_p_plads.h)

