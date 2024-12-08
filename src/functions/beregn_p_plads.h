#ifndef BEREGN_P_PLADS_H
#define BEREGN_P_PLADS_H
#include <stdio.h>
#include <stdlib.h>
#define ANTALPARKERINGSPLADSER 258

// Struct til parkeringsplads
typedef struct {
    int nummer;
    int distance;    // Afstand til indgangen
    int ledighed;    // 1 = ledig, 0 = optaget
    int handicap;    // 1 = handicapvenlig
    int el;          // 1 = elbilplads
    int tid;         // tid
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
/* void læsDataFraFil(const char *filnavn, PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                   Parkeringsplads pladser[], int *antalPladser, int præferenceHandicap, int præferenceEl);
*/
// Læs data fra database
void læsDataFraDatabase(const char *dbFilnavn, PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                        Parkeringsplads pladser[], int *antalPladser, int præferenceHandicap, int præferenceEl);

#endif //BEREGN_P_PLADS_H

/*
#ifndef BEREGN_P_PLADS_H
#define BEREGN_P_PLADS_H
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
#endif //BEREGN_P_PLADS_H
*/