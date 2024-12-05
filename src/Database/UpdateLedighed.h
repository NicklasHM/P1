#ifndef UPDATELEDIGHED_H
#define UPDATELEDIGHED_H

#include <sqlite3.h>

void updateLedighed(sqlite3 *db, const char* parkeringspladsnummer, int newLedighed);

#endif // UPDATELEDIGHED_H
