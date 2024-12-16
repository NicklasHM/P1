#ifndef SIMULERING_H
#define SIMULERING_H

#include "data.h"
#include "beregn_p_plads.h"

void opdaterLedighedTilfældig(Parkeringsplads pladser[], int antalPladser,
                              PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap);

void bilAnkommer(Parkeringsplads pladser[], PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap);

void bilForlader(Parkeringsplads pladser[], int antalPladser, PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap);

void skrivTilFil(const char *filnavn, Parkeringsplads pladser[], int antalPladser);

void kørSimulering(Parkeringsplads pladser[], PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap, int antalPladser);

void rebuildHeaps(PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                  Parkeringsplads pladser[], int antalPladser);

#endif
