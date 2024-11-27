#include "beregn_p_plads.h"
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