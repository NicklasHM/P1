#include "functions/scan_nmrplade.h"
#include "functions/beregn_p_plads.h"
// tjekker branch1
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


