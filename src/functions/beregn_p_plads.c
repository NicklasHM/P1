#include "beregn_p_plads.h"
#include <sqlite3.h>
#include <stdio.h>

// -----------------------------------------------
// Funktioner til heap-operationer
// -----------------------------------------------
void insert(PriorityQueue *pq, Parkeringsplads plads, int score) {
    pq->data[pq->size].plads = plads;
    pq->data[pq->size].score = score;
    int i = pq->size;
    pq->size++;

    // Heapify up
    while (i > 0 && pq->data[i].score > pq->data[(i - 1) / 2].score) {
        HeapNode temp = pq->data[i];
        pq->data[i] = pq->data[(i - 1) / 2];
        pq->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

HeapNode extractMax(PriorityQueue *pq) {
    HeapNode maxNode = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;

    // Heapify down
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int maxIndex = i;
        if (pq->data[2 * i + 1].score > pq->data[maxIndex].score) {
            maxIndex = 2 * i + 1;
        }
        if (2 * i + 2 < pq->size && pq->data[2 * i + 2].score > pq->data[maxIndex].score) {
            maxIndex = 2 * i + 2;
        }
        if (i == maxIndex) {
            break;
        }
        HeapNode temp = pq->data[i];
        pq->data[i] = pq->data[maxIndex];
        pq->data[maxIndex] = temp;
        i = maxIndex;
    }
    return maxNode;
}

// -----------------------------------------------
// Funktioner til scoringsberegning
// -----------------------------------------------
int beregnAfstandScore(Parkeringsplads p) {
    return -p.distance; // Mindre afstand = højere prioritet
}

int beregnTidScore(Parkeringsplads p) {
    return -(p.distance * 2); // Eksempel: Tid proportional med afstand
}

int omkringliggendeLedighed(Parkeringsplads p, Parkeringsplads pladser[], int antalPladser) {
    for (int i = 0; i < antalPladser; i++) {
        if (pladser[i].nummer == p.nummer - 1 || pladser[i].nummer == p.nummer + 1) {
            if (pladser[i].ledighed == 0) {
                return 0; // Omkringliggende plads er optaget
            }
        }
    }
    return 1; // Alle omkringliggende pladser er ledige
}

int beregnLedighedScore(Parkeringsplads p, Parkeringsplads pladser[], int antalPladser, int præferenceHandicap, int præferenceEl) {
    if (præferenceHandicap && p.handicap == 0) {
        return -1000; // Lav prioritet for ikke-handicap pladser
    }
    if (præferenceEl && p.el == 0) {
        return -1000; // Lav prioritet for ikke-el-pladser
    }

    if (omkringliggendeLedighed(p, pladser, antalPladser)) {
        return 100; // Høj prioritet for pladser med ledige omgivelser
    } else {
        return 50; // Lavere prioritet for pladser med optagne omgivelser
    }
}

// -----------------------------------------------
// Indsæt plads i alle heaps
// -----------------------------------------------
void indsætAlleHeaps(PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                     Parkeringsplads p, Parkeringsplads pladser[], int antalPladser, int præferenceHandicap, int præferenceEl) {
    int scoreAfstand = beregnAfstandScore(p);
    int scoreTid = beregnTidScore(p);
    int scoreLedighed = beregnLedighedScore(p, pladser, antalPladser, præferenceHandicap, præferenceEl);

    insert(afstandHeap, p, scoreAfstand);
    insert(tidHeap, p, scoreTid);
    insert(ledighedHeap, p, scoreLedighed);
}

// -----------------------------------------------
// Læs data fra fil
// -----------------------------------------------



// Function to read data from the database
void læsDataFraDatabase(const char *dbFilnavn, PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                        Parkeringsplads pladser[], int *antalPladser, int præferenceHandicap, int præferenceEl) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;
    int index = 0;

    // Open the database
    rc = sqlite3_open(dbFilnavn, &db);
    if (rc) {
        printf("Kan ikke åbne databasen: %s\n", sqlite3_errmsg(db));
        exit(1);
    }

    // Prepare the SQL query with a condition to ensure valid parking spots
    const char *sql = "SELECT Parkeringspladsnummer, Distance, Tid, Ledighed, Handicap, El FROM Parking WHERE Parkeringspladsnummer <= 174";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printf("SQL fejl: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    // Execute the query and process the results
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Parkeringsplads p;
        p.nummer = sqlite3_column_int(stmt, 0);
        p.distance = sqlite3_column_int(stmt, 1);
        p.tid = sqlite3_column_int(stmt, 2);  // Assuming 'Tid' is the third column
        p.ledighed = sqlite3_column_int(stmt, 3);
        p.handicap = sqlite3_column_int(stmt, 4);
        p.el = sqlite3_column_int(stmt, 5);

        pladser[index++] = p;
        indsætAlleHeaps(afstandHeap, tidHeap, ledighedHeap, p, pladser, index, præferenceHandicap, præferenceEl);
    }

    *antalPladser = index;

    // Finalize the statement and close the database
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}



/*
void læsDataFraFil(const char *filnavn, PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                   Parkeringsplads pladser[], int *antalPladser, int præferenceHandicap, int præferenceEl) {
    FILE *fil = fopen(filnavn, "r");
    if (fil == NULL) {
        printf("Kunne ikke åbne filen: %s\n", filnavn);
        exit(1);
    }

    char linje[256];
    int index = 0;
    while (fgets(linje, sizeof(linje), fil)) {
        Parkeringsplads p;
        sscanf(linje, "Parkeringspladsnummer: %d, Distance: %d meter, Ledighed: %d, Handicap: %d, El: %d",
               &p.nummer, &p.distance, &p.ledighed, &p.handicap, &p.el);
        pladser[index++] = p;
        indsætAlleHeaps(afstandHeap, tidHeap, ledighedHeap, p, pladser, *antalPladser, præferenceHandicap, præferenceEl);
    }

    *antalPladser = index;
    fclose(fil);
}
*/