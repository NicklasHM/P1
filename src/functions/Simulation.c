#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sqlite3.h>
#include <time.h>

// Function to update the availability status of a parking spot
void dbupdate(sqlite3 *db, int parkeringspladsnummer, int newLedighed) {
    char *errMsg = 0;
    char sql[256];

    // Prepare the SQL UPDATE statement
    snprintf(sql, sizeof(sql),
             "UPDATE Parking SET Ledighed = %d WHERE Parkeringspladsnummer = %d;",
             newLedighed, parkeringspladsnummer);

    // Execute the SQL command
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        // Handle SQL errors
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        // Debugging output
        printf("Updated Parkeringspladsnummer %d to Ledighed %d\n", parkeringspladsnummer, newLedighed);
    }
}

// Function to simulate parking spot availability changes
void* simulateLedighed(void* arg) {
    sqlite3 *db = (sqlite3*)arg;
    srand(time(NULL)); // Seed for randomness

    while (1) {
        sleep(60);  // Simulate updates every 60 seconds

        sqlite3_stmt *stmt;
        const char* sqlSelect = "SELECT Parkeringspladsnummer, Ledighed FROM Parking;";

        int rc = sqlite3_prepare_v2(db, sqlSelect, -1, &stmt, 0);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
            continue;
        }

        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
            int parkeringspladsnummer = sqlite3_column_int(stmt, 0);
            int currentLedighed = sqlite3_column_int(stmt, 1);

            // Randomly decide whether to update this spot
            if (rand() % 5 == 0) { // Update 20% of spots (adjust as needed)
                int newLedighed = rand() % 2; // Randomly set new state (0 or 1)

                if (currentLedighed != newLedighed) {
                    dbupdate(db, parkeringspladsnummer, newLedighed);
                    printf("Spot %d: %s\n", parkeringspladsnummer,
                           newLedighed ? "Car leaves" : "Car arrives");
                }
            }
        }

        if (rc != SQLITE_DONE) {
            fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        }

        sqlite3_finalize(stmt);
    }

    return NULL;
}
