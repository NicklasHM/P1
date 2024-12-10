#include <stdio.h>
#include <string.h>
#include "scan_nmrplade.h"

void scanNummerpladeOgGemPræferencer(const char *brugerdataFil) {
    char nummerplade[20];
    int præferenceHandicap, præferenceEl, præferenceKriterium;

    // Indtast nummerplade
    printf("Indtast nummerpladen: ");
    scanf("%s", nummerplade);

    // Indtast præferencer
    printf("Ønsker du handicap-parkering? (1 = ja, 0 = nej): ");
    scanf("%d", &præferenceHandicap);
    printf("Ønsker du el-parkering? (1 = ja, 0 = nej): ");
    scanf("%d", &præferenceEl);

    // Indtast prioriteringskriterium
    printf("Hvad vil du prioritere? (1 = afstand, 2 = tid, 3 = ledighed): ");
    scanf("%d", &præferenceKriterium);

    // Åbn filen for at gemme data
    FILE *fil = fopen(brugerdataFil, "a");
    if (fil == NULL) {
        printf("Kunne ikke åbne filen: %s\n", brugerdataFil);
        return;
    }

    // Gem nummerpladen og præferencerne i filen
    fprintf(fil, "Nummerplade: %s, Handicap: %d, El: %d, Kriterium: %d\n",
            nummerplade, præferenceHandicap, præferenceEl, præferenceKriterium);
    fclose(fil);

    printf("Nummerplade og præferencer er blevet gemt i brugerdata.txt.\n");
}
