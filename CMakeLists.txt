cmake_minimum_required(VERSION 3.29)
project(P1Again C)

Set(CMAKE_C_STANDARD 99)

find_package(SQLite3 REQUIRED)

add_executable(Database
        src/Database/database.c
        src/Database/simulateLedighed.c
        src/Database/updateLedighed.c
)
target_link_libraries(Database ${SQLite3_LIBRARIES} pthread)

add_executable(DatabaseTemp
        src/Database/database.c
        src/Database/simulateLedighed.c
        src/Database/updateLedighed.c
)
target_link_libraries(DatabaseTemp ${SQLite3_LIBRARIES} pthread)

add_executable(Main
        src/main.c
        src/functions/beregn_p_plads.c
        src/functions/scan_nmrplade.c
)
target_link_libraries(Main ${SQLite3_LIBRARIES} pthread)