#ifndef DATA_H
#define DATA_H

// Definition af Parkeringsplads-struktur
typedef struct {
    int nummer;
    int handicap;
    int el;
    double distance;
    int tid;
    int ledighed;
} Parkeringsplads;

#endif