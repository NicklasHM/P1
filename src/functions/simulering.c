#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "data.h"
#include "beregn_p_plads.h"
#include "simulering.h"
/**
 * Opdaterer alle parkeringspladser med tilfældig ledighed.
 * Hver plads får værdien 0 (ledig) eller 1 (optaget).
 */
// Genopbygger heaps
void rebuildHeaps(PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                  Parkeringsplads pladser[], int antalPladser) {
    afstandHeap->size = 0;
    tidHeap->size = 0;
    ledighedHeap->size = 0;

    for (int i = 0; i < antalPladser; i++) {
        indsætAlleHeaps(afstandHeap, tidHeap, ledighedHeap, pladser[i], pladser, antalPladser, 0, 0);
    }
}

// Opdaterer alle parkeringspladser tilfældigt til optaget eller ledigt.
void opdaterLedighedTilfældig(Parkeringsplads pladser[], int antalPladser,
                              PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap) {
    for (int i = 0; i < antalPladser; i++) {
        pladser[i].ledighed = rand() % 2; // // Tilfældig ledighed 0 (ledig) eller 1 (optaget)
    }
    rebuildHeaps(afstandHeap, tidHeap, ledighedHeap, pladser, antalPladser);
}

/**
 * Simulerer en bil, der ankommer til parkeringspladsen.
 * Bilen vælger en plads baseret på en tilfældig præference (afstand, tid eller ledighed).
 */
void bilAnkommer(Parkeringsplads pladser[], PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap) {
    int præference = rand() % 3; // Vælg tilfældig præference: 0 = afstand, 1 = tid, 2 = ledighed

    HeapNode valgtPlads;
    int fundet = 0;

    if (præference == 0) { // Præference: afstand
        while (afstandHeap->size > 0) {
            valgtPlads = extractMax(afstandHeap);
            if (valgtPlads.plads.ledighed == 0 && valgtPlads.plads.handicap == 0 && valgtPlads.plads.el == 0) {
                valgtPlads.plads.ledighed = 1; // Markér plads som optaget
                pladser[valgtPlads.plads.nummer - 1].ledighed = 1; // Opdater arrayet
                fundet = 1;
                break;
            }
        }
        printf("Parkeringsplads valgt ud fra afstand: ");
    } else if (præference == 1) { // Præference: tid
        while (tidHeap->size > 0) {
            valgtPlads = extractMax(tidHeap);
            if (valgtPlads.plads.ledighed == 0 && valgtPlads.plads.handicap == 0 && valgtPlads.plads.el == 0) {
                valgtPlads.plads.ledighed = 1; // Mark as occupied
                pladser[valgtPlads.plads.nummer - 1].ledighed = 1; // Update array
                fundet = 1;
                break;
            }
        }
        printf("Parkeringsplads  valgt ud fra tid: ");
    } else { // (præference == 2) Præference: ledighed
        while (ledighedHeap->size > 0) {
            valgtPlads = extractMax(ledighedHeap);
            if (valgtPlads.plads.ledighed == 0 && valgtPlads.plads.handicap == 0 && valgtPlads.plads.el == 0) {
                valgtPlads.plads.ledighed = 1; // Mark as occupied
                pladser[valgtPlads.plads.nummer - 1].ledighed = 1; // Update array
                fundet = 1;
                break;
            }
        }
        printf("Parkeringsplads  valgt ud fra ledighed: ");
    }

    if (fundet) {
        printf("Tildelt plads %d.\n", valgtPlads.plads.nummer);
        rebuildHeaps(afstandHeap, tidHeap, ledighedHeap, pladser, 500); // Synkroniser heaps
    } else {
        printf("Ingen ledige pladser fundet.\n");
    }
}

/**
 * Simulerer en bil, der forlader parkeringspladsen.
 * Vælger en tilfældig optaget plads og gør den ledig.
 */
void bilForlader(Parkeringsplads pladser[], int antalPladser, PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap) {
    int occupiedCount = 0;
    for (int i = 0; i < antalPladser; i++) {
        if (pladser[i].ledighed == 1) {
            occupiedCount++;
        }
    }

    if (occupiedCount == 0) {
        printf("Ingen biler at forlade.\n");
        return;
    }

    int randomIndex;
    do {
        randomIndex = rand() % antalPladser; // Vælg tilfældig plads
    } while (pladser[randomIndex].ledighed == 0);

    pladser[randomIndex].ledighed = 0; // Gør pladsen ledig
    printf("Bil forlod plads %d.\n", pladser[randomIndex].nummer);
    rebuildHeaps(afstandHeap, tidHeap, ledighedHeap, pladser, antalPladser); // Synkroniser heaps
}

/**
 * Skriver tilstanden for alle parkeringspladser til en logfil.
 *
 */
void skrivTilFil(const char *filnavn, Parkeringsplads pladser[], int antalPladser) {
    FILE *fil = fopen(filnavn, "w"); // Append til filen
    if (fil == NULL) {
        printf("Kunne ikke åbne filen: %s\n", filnavn);
        return;
    }
    // Skriv parkeringsstatus
    for (int i = 0; i < antalPladser; i++) {
        fprintf(fil, "Parkeringsplads: %03d\tHandicap: %d\tEl: %d\tDistance: %.1f\tTid: %d\tLedighed: %d\n",
                pladser[i].nummer, pladser[i].handicap, pladser[i].el, pladser[i].distance, pladser[i].tid, pladser[i].ledighed);
    }

    fclose(fil);
}

/**
 * Kører simuleringen, hvor biler ankommer og forlader.
 * Simuleringen opdaterer logfilen og heaps.
 */
void kørSimulering(Parkeringsplads pladser[], PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap, int antalPladser) {
    srand(time(NULL)); // Seed for randomness

    opdaterLedighedTilfældig(pladser, antalPladser, afstandHeap, tidHeap, ledighedHeap);
    skrivTilFil("simulering_log.txt", pladser, antalPladser);

    for (int i = 0; i < 10; i++) { // Kør 10 iterationer
        bilAnkommer(pladser, afstandHeap, tidHeap, ledighedHeap);
        skrivTilFil("simulering_log.txt", pladser, antalPladser);
        sleep(5); // Vent 5 sekunder
        bilForlader(pladser, antalPladser, afstandHeap, tidHeap, ledighedHeap);
        skrivTilFil("simulering_log.txt", pladser, antalPladser);
    }
}
