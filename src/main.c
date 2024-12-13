#include <stdio.h>
#include <string.h>

#include "functions/data.h"
#include "functions/beregn_p_plads.h"
#include "functions/scan_nmrplade.h"
#include "functions/simulering.h"
/**
 * Hovedprogrammet til parkeringssystemet.
 * Brugeren kan vælge at indtaste præferencer eller køre en simulation.
 */
int main() {
    PriorityQueue afstandHeap = { .size = 0 };
    PriorityQueue tidHeap = { .size = 0 };
    PriorityQueue ledighedHeap = { .size = 0 };
    Parkeringsplads pladser[500];
    int antalPladser = 0;

    // Læs parkeringsplads-data fra Datafil.txt
    læsDataFraFil("Datafil.txt", &afstandHeap, &tidHeap, &ledighedHeap, pladser, &antalPladser, 0, 0);

    // Menu til valg af programtilstand
    printf("Velkommen til parkeringssystemet!\n");
    printf("Vælg en mulighed:\n");
    printf("1. Kør hovedprogrammet (brugeren indtaster præferencer).\n");
    printf("2. Start simuleringen.\n");
    printf("Indtast dit valg (1 eller 2): ");

    int valg;
    if (scanf("%d", &valg) != 1 || (valg != 1 && valg != 2)) {
        printf("Ugyldigt valg. Programmet afsluttes.\n");
        return 0;
    }
    if (valg == 1) {
    // Hovedprogram: Brugerinput
    // Brugeren indtaster præferencer
    int præferenceHandicap, præferenceEl, præferenceKriterium;
    char input[256];
        const char *filename = "brugerdata.txt";
        FILE *file = fopen(filename, "a+");
        if (file == NULL) {
            printf("Error opening file '%s'!\n", filename);
            return 1;
        }
    while (getchar() != '\n');
    printf("indtast nummerplade: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    if (line_exists(file, input)) {
        int el, hk, p;
        sscanf(input, "%*s %d %d %d", &hk, &el, &p);  // %*s ignorer første del
        printf("%d %d %d", hk, el, p);
        printf("Read input: '%s'\n", input);

        input[strcspn(input, "\n")] = 0;

        if(hk) {
            for (int i = 0; i < antalPladser; i++) {
                if (pladser[i].handicap == 1 && pladser[i].ledighed == 1) {
                    printf("Første ledige handicap-parkering: Plads %d, Afstand: %.2f meter\n",
                           pladser[i].nummer, pladser[i].distance);
                    return 0; // Stop programmet her
                }
            }
            printf("Ingen ledige handicap-pladser.\n");
            return 0;
        } if(el) {
            for (int i = 0; i < antalPladser; i++) {
                if (pladser[i].el == 1 && pladser[i].ledighed == 1) {
                    printf("Første ledige el-parkering: Plads %d, Afstand: %.2f meter\n",
                           pladser[i].nummer, pladser[i].distance);
                    return 0; // Stop programmet her
                }
            }
            printf("Ingen ledige el-pladser.\n");
            return 0;
        }
        switch (p) {
            case 1:
                while (afstandHeap.size > 0) {
                    HeapNode bedsteAfstand = extractMax(&afstandHeap);
                    if (bedsteAfstand.plads.handicap == 0 && bedsteAfstand.plads.el == 0 && bedsteAfstand.plads.ledighed == 1) {
                        printf("Bedste plads baseret på afstand: Plads %d med afstand %.2f meter\n",
                               bedsteAfstand.plads.nummer, bedsteAfstand.plads.distance);
                        return 0;
                    }
                }
                printf("Ingen egnede pladser fundet.\n");
                break;
            case 2:
                while (tidHeap.size > 0) {
                    HeapNode bedsteTid = extractMax(&tidHeap);
                    if (bedsteTid.plads.handicap == 0 && bedsteTid.plads.el == 0 && bedsteTid.plads.ledighed == 1) {
                        printf("Bedste plads baseret på tid: Plads %d med tid %d sekunder\n",
                               bedsteTid.plads.nummer, bedsteTid.plads.tid);
                        return 0;
                    }
                }
                printf("Ingen egnede pladser fundet.\n");
                break;
            case 3:
                while (ledighedHeap.size > 0) {
                    HeapNode bedsteLedighed = extractMax(&ledighedHeap);
                    if (bedsteLedighed.plads.handicap == 0 && bedsteLedighed.plads.el == 0 && bedsteLedighed.plads.ledighed == 1) {
                        printf("Bedste plads baseret på ledighed: Plads %d med ledighed %d (lavere er bedre)\n",
                               bedsteLedighed.plads.nummer, bedsteLedighed.plads.ledighed);
                        return 0;
                    }
                }
                printf("Ingen egnede pladser fundet.\n");
                break;
            default:
                printf("Ugyldigt valg.\n");
        }

    }
    printf("Ønsker du handicap-parkering? (1 = ja, 0 = nej): ");
    scanf("%d", &præferenceHandicap);

    if (præferenceHandicap) {
        // Find første ledige handicap-parkering
        præferenceHandicap=1;
        præferenceEl=0;
        write_to_file(file, input, præferenceHandicap, præferenceEl, præferenceKriterium);
        for (int i = 0; i < antalPladser; i++) {
            if (pladser[i].handicap == 1 && pladser[i].ledighed == 1) {
                printf("Første ledige handicap-parkering: Plads %d, Afstand: %.2f meter\n",
                       pladser[i].nummer, pladser[i].distance);
                return 0; // Stop programmet her
            }
        }
        printf("Ingen ledige handicap-pladser.\n");
        return 0;
    }

    printf("Ønsker du el-parkering? (1 = ja, 0 = nej): ");
    scanf("%d", &præferenceEl);

    if (præferenceEl) {
        // Find nærmeste ledige el-parkering
        præferenceHandicap=0;
        præferenceEl=1;
        write_to_file(file, input, præferenceHandicap, præferenceEl, præferenceKriterium);
        Parkeringsplads nærmesteEl = { .distance = 1e9 }; // Sæt stor værdi som standard
        int fundet = 0;
        for (int i = 0; i < antalPladser; i++) {
            if (pladser[i].el == 1 && pladser[i].ledighed == 1 && pladser[i].distance < nærmesteEl.distance) {
                nærmesteEl = pladser[i];
                fundet = 1;
            }
        }
        if (fundet) {
            printf("Nærmeste ledige el-parkering: Plads %d, Afstand: %.2f meter\n",
                   nærmesteEl.nummer, nærmesteEl.distance);
            return 0; // Stop programmet her
        } else {
            printf("Ingen ledige el-pladser.\n");
            return 0;
        }
    }

    // Hvis hverken handicap eller el vælges, spørg efter præferencer
    printf("Hvad vil du prioritere? (1 = afstand, 2 = tid, 3 = ledighed): ");
    scanf("%d", &præferenceKriterium);
    write_to_file(file, input, præferenceHandicap, præferenceEl, præferenceKriterium);
    // Håndter brugerens præference
    if (præferenceKriterium == 1) {
        while (afstandHeap.size > 0) {
            HeapNode bedsteAfstand = extractMax(&afstandHeap);
            if (bedsteAfstand.plads.handicap == 0 && bedsteAfstand.plads.el == 0 && bedsteAfstand.plads.ledighed == 1) {
                printf("Bedste plads baseret på afstand: Plads %d med afstand %.2f meter\n",
                       bedsteAfstand.plads.nummer, bedsteAfstand.plads.distance);
                return 0;
            }
        }
        printf("Ingen egnede pladser fundet.\n");
    } else if (præferenceKriterium == 2) {
        while (tidHeap.size > 0) {
            HeapNode bedsteTid = extractMax(&tidHeap);
            if (bedsteTid.plads.handicap == 0 && bedsteTid.plads.el == 0 && bedsteTid.plads.ledighed == 1) {
                printf("Bedste plads baseret på tid: Plads %d med tid %d sekunder\n",
                       bedsteTid.plads.nummer, bedsteTid.plads.tid);
                return 0;
            }
        }
        printf("Ingen egnede pladser fundet.\n");
    } else if (præferenceKriterium == 3) {
        while (ledighedHeap.size > 0) {
            HeapNode bedsteLedighed = extractMax(&ledighedHeap);
            if (bedsteLedighed.plads.handicap == 0 && bedsteLedighed.plads.el == 0 && bedsteLedighed.plads.ledighed == 1) {
                printf("Bedste plads baseret på ledighed: Plads %d med ledighed %d (lavere er bedre)\n",
                       bedsteLedighed.plads.nummer, bedsteLedighed.plads.ledighed);
                return 0;
            }
        }
        printf("Ingen egnede pladser fundet.\n");
    } else {
        printf("Ugyldigt valg.\n");
    }


    } else if (valg == 2) {
        // Kør simulering
        kørSimulering(pladser, &afstandHeap, &tidHeap, &ledighedHeap, antalPladser);
    } else {
        printf("Ugyldigt valg. Programmet afsluttes.\n");
    }

    return 0;
}
