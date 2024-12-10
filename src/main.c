#include "functions/Simulation.h"
#include "functions/scan_nmrplade.h"
#include "functions/beregn_p_plads.h"
#include <sqlite3.h>
#include <pthread.h>
#include <stdio.h>
// Hovedprogram

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("ParkingFacility.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    // Start simulation thread
    pthread_t simulationThread;
    if (pthread_create(&simulationThread, NULL, simulateLedighed, (void *)db)) {
        printf("Fejl ved oprettelse af simulerings-tråd\n");
        sqlite3_close(db);
        return 1;
    }

    PriorityQueue afstandHeap = { .size = 0 };
    PriorityQueue tidHeap = { .size = 0 };
    PriorityQueue ledighedHeap = { .size = 0 };
    Parkeringsplads pladser[135];
    int antalPladser = 0;

    // Brugeren vælger præferencer
    int præferenceHandicap, præferenceEl;
    printf("Ønsker du handicap-parkering? (1 = ja, 0 = nej): ");
    scanf("%d", &præferenceHandicap);
    printf("Ønsker du el-parkering? (1 = ja, 0 = nej): ");
    scanf("%d", &præferenceEl);

    // Læs data fra database
    læsDataFraDatabase("ParkingFacility.db", &afstandHeap, &tidHeap, &ledighedHeap, pladser, &antalPladser, præferenceHandicap, præferenceEl);

    // Brugeren vælger en præference
    int valg;
    printf("Vælg præference: 1 for afstand, 2 for tid, 3 for ledighed: ");
    scanf("%d", &valg);

    if (valg == 1) {
        printf("Bedste plads baseret på afstand: ");
        HeapNode bedsteAfstand = extractMax(&afstandHeap);
        if (præferenceHandicap && bedsteAfstand.plads.handicap == 0) {
            printf("Ingen ledige handicap-pladser fundet.\n");
        } else {
            printf("Plads %d med afstand %d\n", bedsteAfstand.plads.nummer, -bedsteAfstand.score);
            // Change the ledighed status in the database for the selected parking space
            ChangeLedighed(db, bedsteAfstand.plads.nummer, 0); // Mark the space as taken
        }
    } else if (valg == 2) {
        printf("Bedste plads baseret på tid: ");
        HeapNode bedsteTid = extractMax(&tidHeap);
        if (præferenceHandicap && bedsteTid.plads.handicap == 0) {
            printf("Ingen ledige handicap-pladser fundet.\n");
        } else {
            printf("Plads %d med tidsscore %d\n", bedsteTid.plads.nummer, -bedsteTid.score);
            ChangeLedighed(db, bedsteTid.plads.nummer, 0);
        }
    } else if (valg == 3) {
        printf("Bedste plads baseret på ledighed: ");
        HeapNode bedsteLedighed = extractMax(&ledighedHeap);
        if (præferenceHandicap && bedsteLedighed.plads.handicap == 0) {
            printf("Ingen ledige handicap-pladser fundet.\n");
        } else {
            printf("Plads %d med ledighedsscore %d\n", bedsteLedighed.plads.nummer, bedsteLedighed.score);
            ChangeLedighed(db, bedsteLedighed.plads.nummer, 0);
        }
    } else {
        printf("Ugyldigt valg.\n");
    }
    // Wait for simulation thread to finish (if needed, or exit gracefully)
    pthread_join(simulationThread, NULL);
    sqlite3_close(db);
}

/*
    const char *filename = "Nummerplader.txt";
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error opening file '%s'!\n", filename);
        return 1;
    }

    char input[256];
    printf("Enter numberplate to write to the file (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Fjerner newline

        if (strcmp(input, "exit") == 0) {
            break;
        }

        write_to_file(file, input);
    }

    fclose(file);

    printf("\nUser data successfully saved to '%s'.\n", filename);
    printf("\nContent of the file:\n");
    print_file_content(filename);

    return 0;
}
*/
/*
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

    const char *filename = "Nummerplader.txt";
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error opening file '%s'!\n", filename);
        return 1;
    }

    char input[256];
    printf("Enter numberplate to write to the file (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Fjerner newline

        if (strcmp(input, "exit") == 0) {
            break;
        }

        write_to_file(file, input);
    }

    fclose(file);

    printf("\nUser data successfully saved to '%s'.\n", filename);
    printf("\nContent of the file:\n");
    print_file_content(filename);

    return 0;
}

*/
