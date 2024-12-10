#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "simulateLedighed.h"
#include "updateLedighed.h"

// Global database variable
sqlite3 *db;

// Function to create the database and populate it
/*
void createDatabase() {
    char *errMsg = 0;
    int rc;

    // SQL statement to create the table
    const char *sqlCreateTable =
        "CREATE TABLE IF NOT EXISTS Parking ("
        "Parkeringspladsnummer INTEGER PRIMARY KEY, "
        "Distance INTEGER, "
        "Tid INTEGER, "
        "Ledighed INTEGER, "
        "Handicap INTEGER, "
        "El INTEGER);";

    // Execute SQL statement to create the table
    rc = sqlite3_exec(db, sqlCreateTable, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return;
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    // Seed the random number generator
    srand(time(0));

    int totalSpots = 174;
    int spotsPerFloor = 58;
    int floorCount = 3;

    for (int floor = 0; floor < floorCount; floor++) {
        int handicapCount = 0;
        int elCount = 0;

        for (int spot = 1; spot <= spotsPerFloor; spot++) {
            int parkeringspladsnummer = floor * spotsPerFloor + spot;

            int distance = parkeringspladsnummer * 2;
            int tid = (rand() % 15) + 1;
            int ledighed = rand() % 2;
            int handicap = 0;
            int el = 0;

            // Assign 2 handicap spots and 3 electric spots per floor
            if (handicapCount < 2) {
                handicap = 1;
                handicapCount++;
            } else if (elCount < 3) {
                el = 1;
                elCount++;
            }

            char sqlInsert[256];
            snprintf(sqlInsert, sizeof(sqlInsert),
                     "INSERT OR IGNORE INTO Parking (Parkeringspladsnummer, Distance, Tid, Ledighed, Handicap, El) "
                     "VALUES (%d, %d, %d, %d, %d, %d);",
                     parkeringspladsnummer, distance, tid, ledighed, handicap, el);

            rc = sqlite3_exec(db, sqlInsert, 0, 0, &errMsg);
            if (rc != SQLITE_OK) {
                fprintf(stderr, "SQL error: %s\n", errMsg);
                sqlite3_free(errMsg);
            }
        }
    }

    printf("Database created and populated successfully.\n");
}
*/

int main() {
    int rc = sqlite3_open("ParkingFacility.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

   // createDatabase();

    // Start the simulation in a separate thread
    pthread_t simulationThread;
    pthread_create(&simulationThread, NULL, simulateLedighed, NULL);

    int parkeringspladsnummer;
    char parkeringspladsnummer_str[10];
    int newLedighed;

    while (1) {
        printf("Enter Parkeringspladsnummer to update: ");
        scanf("%d", &parkeringspladsnummer);
        printf("Enter new Ledighed (0 or 1): ");
        scanf("%d", &newLedighed);

        snprintf(parkeringspladsnummer_str, sizeof(parkeringspladsnummer_str), "%d", parkeringspladsnummer);
        updateLedighed(db, parkeringspladsnummer_str, newLedighed);
    }

    sqlite3_close(db);
    return 0;
}
