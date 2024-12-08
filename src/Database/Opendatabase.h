#ifndef OPEN_DATABASE_H
#define OPEN_DATABASE_H

#include <sqlite3.h>
#include <pthread.h>

// Declare global database variable
extern sqlite3 *db;

// Function prototypes
void updateLedighed(sqlite3 *db, const char* parkeringspladsnummer, int newLedighed);
void* simulateLedighed(void* arg);


#endif