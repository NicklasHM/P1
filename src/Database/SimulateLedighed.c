#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "simulateLedighed.h"
#include "updateLedighed.h"

extern sqlite3 *db;

void* simulateLedighed(void* arg) {
    while (1) {
        sleep(30);  // Sleep for 1 minute

        sqlite3_stmt *stmt;
        const char* sqlSelect = "SELECT Parkeringspladsnummer, Ledighed FROM Parking;";

        int rc = sqlite3_prepare_v2(db, sqlSelect, -1, &stmt, 0);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
            continue;
        }

        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
            const char* parkeringspladsnummer = (const char*)sqlite3_column_text(stmt, 0);
            int currentLedighed = sqlite3_column_int(stmt, 1);

            int newLedighed = rand() % 2;

            if (currentLedighed != newLedighed) {
                updateLedighed(db, parkeringspladsnummer, newLedighed);
                printf("Spot %s: %s\n", parkeringspladsnummer, newLedighed ? "Car leaves" : "Car arrives");
            }
        }

        if (rc != SQLITE_DONE) {
            fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        }

        sqlite3_finalize(stmt);
    }
    return NULL;
}
