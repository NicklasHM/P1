#include <sqlite3.h>
#ifndef SIMULATION_H
#define SIMULATION_H
// function to simulate
void* simulateLedighed(void* arg);
void dbupdate(sqlite3 *db, int parkeringspladsnummer, int newLedighed);
#endif //SIMULATION_H
