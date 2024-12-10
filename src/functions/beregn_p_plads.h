#ifndef BEREGN_P_PLADS_H
#define BEREGN_P_PLADS_H
#include "data.h"

typedef struct {
    Parkeringsplads plads;
    int score;
} HeapNode;

typedef struct {
    HeapNode data[500];
    int size;
} PriorityQueue;

// Funktioner
void læsDataFraFil(const char *filnavn, PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                   Parkeringsplads pladser[], int *antalPladser, int præferenceHandicap, int præferenceEl);

void indsætAlleHeaps(PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                     Parkeringsplads plads, Parkeringsplads pladser[], int antalPladser, int præferenceHandicap, int præferenceEl);

int beregnAfstandScore(Parkeringsplads p);
int beregnTidScore(Parkeringsplads p);
int beregnLedighedScore(Parkeringsplads p, Parkeringsplads pladser[], int antalPladser, int præferenceHandicap, int præferenceEl);

void insert(PriorityQueue *pq, Parkeringsplads plads, int score);
HeapNode extractMax(PriorityQueue *pq);

#endif
