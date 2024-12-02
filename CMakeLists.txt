cmake_minimum_required(VERSION 3.29)
project(P1AGAIN C)

set(CMAKE_C_STANDARD 99)

# Set the SQLite3 include and library paths
include_directories(/opt/homebrew/opt/sqlite/include)
link_directories(/opt/homebrew/opt/sqlite/lib)

# Add the source files for the main program
set(SOURCES
        src/Database/database.c
        src/Database/simulateLedighed.c
        src/Database/updateLedighed.c
)

# Create the main executable target
add_executable(Database ${SOURCES})

# Create the DatabaseOnly executable target
add_executable(DatabaseTemp
        src/Database/database.c
        src/Database/simulateLedighed.c
        src/Database/updateLedighed.c
)

# Link the SQLite3 and pthread libraries to the targets
target_link_libraries(Database sqlite3 pthread)
target_link_libraries(DatabaseTemp sqlite3 pthread)


enable_testing()

add_subdirectory(src)



