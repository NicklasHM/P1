#include <sqlite3.h>
#include <stdio.h>
#include "updateLedighed.h"

void updateLedighed(sqlite3 *db, const char* parkeringspladsnummer, int newLedighed) {
    char *errMsg = 0;
    char sqlUpdate[256];

    snprintf(sqlUpdate, sizeof(sqlUpdate), "UPDATE Parking SET Ledighed = %d WHERE Parkeringspladsnummer = '%s';", newLedighed, parkeringspladsnummer);

    int rc = sqlite3_exec(db, sqlUpdate, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Ledighed updated successfully\n");
    }
}
