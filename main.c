#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int parknumber;
    int distance;
    int is_available;
    int disabled;
    int el;
} PARKING_SPOT;

// Heapify funktion til at opbygge min-heap
void heapify(PARKING_SPOT arr[], int n, int i) {
    int smallest = i; // Rod
    int left = 2 * i + 1; // Venstre barn
    int right = 2 * i + 2; // Højre barn

    // Find det mindste element mellem rod, venstre og højre barn
    if (left < n && arr[left].distance < arr[smallest].distance) {
        smallest = left;
    }
    if (right < n && arr[right].distance < arr[smallest].distance) {
        smallest = right;
    }

    // Swap og rekursiv heapify, hvis nødvendigt
    if (smallest != i) {
        PARKING_SPOT temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        heapify(arr, n, smallest);
    }
}

// Bygger en min-heap
void buildHeap(PARKING_SPOT arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Udtræk det mindste element (nærmeste plads) fra heapen
PARKING_SPOT extractMin(PARKING_SPOT arr[], int* n) {
    PARKING_SPOT root = arr[0];
    arr[0] = arr[--(*n)];
    heapify(arr, *n, 0);
    return root;
}

int main(void) {
    FILE *fin = fopen("datafil.txt", "r");
    if (fin == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    // Array til at gemme parkeringspladser
    PARKING_SPOT parkingspots[100]; // Antag maks. 100 pladser
    int count = 0;

    char linje[256];
    while (fgets(linje, sizeof(linje), fin) != NULL) {
        PARKING_SPOT pspot;

        // Fjern newline og parse linjen
        linje[strcspn(linje, "\n")] = '\0';

        if (sscanf(linje, "Parkeringspladsnummer: %d, Distance: %d meter, Ledighed: %d, Handicap: %d, El: %d",
                   &pspot.parknumber, &pspot.distance, &pspot.is_available, &pspot.disabled, &pspot.el) == 5) {
            parkingspots[count++] = pspot;
        } else {
            fprintf(stderr, "Fejl ved parsing af linje: %s\n", linje);
        }
    }
    fclose(fin);

    // Byg min-heap fra parkeringspladserne
    buildHeap(parkingspots, count);

    // Find den bedste plads
    int n = count;
    while (n > 0) {
        PARKING_SPOT best_spot = extractMin(parkingspots, &n);
        if (best_spot.is_available) { // Tjek kun ledige pladser
            printf("Bedste parkeringsplads:\n");
            printf("Nummer: %d, Afstand: %d meter, Handicap: %d, El: %d\n",
                   best_spot.parknumber, best_spot.distance, best_spot.disabled, best_spot.el);
            break;
        }
    }

    if (n == 0) {
        printf("Ingen ledige parkeringspladser fundet.\n");
    }

    return 0;
}
