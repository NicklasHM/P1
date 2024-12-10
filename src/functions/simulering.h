#ifndef SIMULERING_H
#define SIMULERING_H

#include "data.h"
#include "beregn_p_plads.h"

// Randomly update parking availability and synchronize heaps
void opdaterLedighedTilfældig(Parkeringsplads pladser[], int antalPladser,
                              PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap);

// Simulate a car arriving and synchronizing heaps
void bilAnkommer(Parkeringsplads pladser[], PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap);

// Simulate a car leaving and synchronizing heaps
void bilForlader(Parkeringsplads pladser[], int antalPladser, PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap);

// Write the current state of all parking spaces to a file
void skrivTilFil(const char *filnavn, Parkeringsplads pladser[], int antalPladser);

// Run the simulation, including car arrivals and departures
void kørSimulering(Parkeringsplads pladser[], PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap, int antalPladser);

// Rebuild all heaps based on the current state of parking spaces
void rebuildHeaps(PriorityQueue *afstandHeap, PriorityQueue *tidHeap, PriorityQueue *ledighedHeap,
                  Parkeringsplads pladser[], int antalPladser);

#endif
