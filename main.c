#include <stdio.h>
#include <stdlib.h>
#define ANTALPARKERINGSPLADSER 10

// Struct til parkeringsplads
typedef struct {
    int nummer;
    int distance;    // Afstand til indgangen
    int ledighed;    // 1 = ledig, 0 = optaget
    int handicap;    // 1 = handicapvenlig
    int el;          // 1 = elbilplads
} Parkeringsplads;

// Struct til heap-node
typedef struct {
    Parkeringsplads plads;
    int score;       // Beregnet score for denne plads
} HeapNode;

// Struct til heap
typedef struct {
    HeapNode data[ANTALPARKERINGSPLADSER]; // Maksimalt 500 pladser
    int size;           // Antal elementer i heapen
} PriorityQueue;

// Funktioner til heap-operationer
void insert(PriorityQueue *pq, Parkeringsplads plads, int score);
HeapNode extractMax(PriorityQueue *pq);

// Funktioner til scoringsberegning
int beregnAfstandScore(Parkeringsplads p);
int beregnTidScore(Parkeringsplads p);
int omkringliggendeLedighed(Parkeringsplads p, Parkeringsplads pladser[], int antalPladser);
int beregnLedighedScore(Parkeringsplads p, Parkeringsplads pladser[], int antalPladser, int præferenceHandicap, int præferenceEl);

// Indsæt plads i alle heaps
void indsætAlleHeaps(PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                     Parkeringsplads p, Parkeringsplads pladser[], int antalPladser, int præferenceHandicap, int præferenceEl);

// Læs data fra fil
void læsDataFraFil(const char *filnavn, PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                   Parkeringsplads pladser[], int *antalPladser, int præferenceHandicap, int præferenceEl);

// Hovedprogram
int main() {
    PriorityQueue afstandHeap = { .size = 0 };
    PriorityQueue tidHeap = { .size = 0 };
    PriorityQueue ledighedHeap = { .size = 0 };
    Parkeringsplads pladser[500];
    int antalPladser = 0;

    // Brugeren vælger præferencer
    int præferenceHandicap, præferenceEl;
    printf("Ønsker du handicap-parkering? (1 = ja, 0 = nej): ");
    scanf("%d", &præferenceHandicap);
    printf("Ønsker du el-parkering? (1 = ja, 0 = nej): ");
    scanf("%d", &præferenceEl);

    // Læs data fra fil
    læsDataFraFil("datafil.txt", &afstandHeap, &tidHeap, &ledighedHeap, pladser, &antalPladser, præferenceHandicap, præferenceEl);

    // Brugeren vælger en præference
    int valg;
    printf("Vælg præference: 1 for afstand, 2 for tid, 3 for ledighed: ");
    scanf("%d", &valg);

    if (valg == 1) {
        printf("Bedste plads baseret på afstand: ");
        HeapNode bedsteAfstand = extractMax(&afstandHeap);
        printf("Plads %d med afstand %d\n", bedsteAfstand.plads.nummer, -bedsteAfstand.score);
    } else if (valg == 2) {
        printf("Bedste plads baseret på tid: ");
        HeapNode bedsteTid = extractMax(&tidHeap);
        printf("Plads %d med tidsscore %d\n", bedsteTid.plads.nummer, -bedsteTid.score);
    } else if (valg == 3) {
        printf("Bedste plads baseret på ledighed: ");
        HeapNode bedsteLedighed = extractMax(&ledighedHeap);
        printf("Plads %d med ledighedsscore %d\n", bedsteLedighed.plads.nummer, bedsteLedighed.score);
    } else {
        printf("Ugyldigt valg.\n");
    }

    return 0;
}

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
