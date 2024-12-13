#include <stdio.h>
#include <stdlib.h>
#include "beregn_p_plads.h"

/**
 * Læser parkeringsdata fra en fil og initialiserer prioritetskøer og pladser.
 *
 * - Parser hver linje i filen og opretter en parkeringsplads.
 * - Tilføjer hver plads til arrayet `pladser` og prioritetskøerne.
 *
 * @param filnavn Navnet på datafilen.
 * @param afstandHeap Heap baseret på afstand.
 * @param tidHeap Heap baseret på tid.
 * @param ledighedHeap Heap baseret på ledighed.
 * @param pladser Array af parkeringspladser.
 * @param antalPladser Pointer til antal pladser i arrayet.
 * @param præferenceHandicap Brugerens præference for handicappladser.
 * @param præferenceEl Brugerens præference for el-pladser.
 */
void læsDataFraFil(const char *filnavn, PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                   Parkeringsplads pladser[], int *antalPladser, int præferenceHandicap, int præferenceEl) {
    FILE *fil = fopen(filnavn, "r");
    if (fil == NULL) {
        printf("Kunne ikke åbne filen: %s\n", filnavn);
        exit(1); // Afslut programmet, hvis filen ikke kan åbnes
    }

    // Læs hele filen ind i hukommelsen
    int index = 0;
    char linje[256];
    while (fgets(linje, sizeof(linje), fil)) {
        Parkeringsplads p;

        // Læs data fra linjen og initialiser parkeringsplads
        sscanf(linje, "Parkeringsplads: %d Handicap: %d El: %d Distance: %lf Tid: %d Ledighed: %d",
               &p.nummer, &p.handicap, &p.el, &p.distance, &p.tid, &p.ledighed);

        // Tilføj pladsen til arrayet
        pladser[index++] = p;
    }

    fclose(fil); // Luk filen efter indlæsning
    *antalPladser = index; // Opdater antallet af indlæste pladser

    // Beregn scorer og indsæt alle pladser i prioritetskøerne
    for (int i = 0; i < index; i++) {
        indsætAlleHeaps(afstandHeap, tidHeap, ledighedHeap, pladser[i], pladser, index, præferenceHandicap, præferenceEl);
    }
}


/**
 * Indsætter en parkeringsplads i alle prioritetskøer.
 *
 * - Beregner scores for afstand, tid og ledighed.
 * - Tilføjer pladsen til de relevante heaps.
 *
 * @param afstandHeap Heap rangeret efter afstand.
 * @param tidHeap Heap rangeret efter tid.
 * @param ledighedHeap Heap rangeret efter ledighed.
 * @param plads Parkeringspladsen der skal indsættes.
 * @param pladser Array af parkeringspladser.
 * @param antalPladser Antallet af parkeringspladser.
 * @param præferenceHandicap Brugerens præference for handicappladser.
 * @param præferenceEl Brugerens præference for el-pladser.
 */
void indsætAlleHeaps(PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                     Parkeringsplads plads, Parkeringsplads pladser[], int antalPladser, int præferenceHandicap, int præferenceEl) {
    int scoreAfstand = beregnAfstandScore(plads);
    int scoreTid = beregnTidScore(plads);
    int scoreLedighed = beregnLedighedScore(plads, pladser, antalPladser, præferenceHandicap, præferenceEl);

    insert(afstandHeap, plads, scoreAfstand);
    insert(tidHeap, plads, scoreTid);
    insert(ledighedHeap, plads, scoreLedighed);
}

/**
 * Beregner afstandsscoren for en parkeringsplads.
 * Mindre afstand giver højere prioritet.
 *
 * @param p Parkeringspladsen der evalueres.
 * @return Afstandsscore.
 */
int beregnAfstandScore(Parkeringsplads p) {
    return (int)(-p.distance); // Mindre afstand = højere prioritet / Negativ afstand for at prioritere mindre afstande
}

/**
 * Beregner tidsscoren for en parkeringsplads.
 * Mindre tid giver højere prioritet.
 *
 * @param p Parkeringspladsen der evalueres.
 * @return Tidsscore.
 */
int beregnTidScore(Parkeringsplads p) {
    return -p.tid; // Mindre tid = højere prioritet
}

/**
 * Beregner ledighedsscoren for en parkeringsplads.
 * Bruges til at prioritere baseret på naboer og brugerpræferencer.
 *
 * @param p Parkeringspladsen der evalueres.
 * @param pladser Array af parkeringspladser.
 * @param antalPladser Antallet af parkeringspladser.
 * @param præferenceHandicap Brugerens præference for handicappladser.
 * @param præferenceEl Brugerens præference for el-pladser.
 * @return Ledighedsscore.
 */
int beregnLedighedScore(Parkeringsplads p, Parkeringsplads pladser[], int antalPladser, int præferenceHandicap, int præferenceEl) {
    // Prioritering baseret på brugerpræferencer
    if (præferenceHandicap && !p.handicap) {
        return -1000; // Lav prioritet for ikke-handicap pladser
    }
    if (præferenceEl && !p.el) {
        return -1000; // Lav prioritet for ikke-el-pladser
    }

    // Kontroller omkringliggende pladser for ledighed
    int ledigeNaboer = 0;
    for (int i = 0; i < antalPladser; i++) {
        if (pladser[i].nummer == p.nummer - 1 || pladser[i].nummer == p.nummer + 1) {
            if (pladser[i].ledighed == 0) {
                ledigeNaboer++;
            }
        }
    }

    // Høj prioritet for pladser med flere ledige naboer // Flere ledige naboer giver højere prioritet
    return ledigeNaboer * 10 - (p.ledighed * 50);
}

/**
 * Indsætter en parkeringsplads i en prioritetskø baseret på dens score.
 *
 * @param pq Prioritetskøen hvor pladsen skal indsættes.
 * @param plads Parkeringspladsen der skal indsættes.
 * @param score Prioritetsscore.
 */
void insert(PriorityQueue *pq, Parkeringsplads plads, int score) {
    pq->data[pq->size].plads = plads;
    pq->data[pq->size].score = score;
    int i = pq->size;
    pq->size++;

    // Reparer heapen (heapify up)
    while (i > 0 && pq->data[i].score > pq->data[(i - 1) / 2].score) {
        HeapNode temp = pq->data[i];
        pq->data[i] = pq->data[(i - 1) / 2];
        pq->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
/**
 * Fjerner og returnerer noden med højeste prioritet fra en prioritetskø.
 *
 * @param pq Prioritetskøen hvorfra noden fjernes.
 * @return Noden med højeste prioritet.
 */
HeapNode extractMax(PriorityQueue *pq) {
    HeapNode maxNode = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;

    // Reparer heapen (heapify down)
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

