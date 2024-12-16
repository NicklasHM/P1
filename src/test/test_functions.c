#include "mtest.h"
#include "../functions/beregn_p_plads.h"
#include "../functions/data.h"
#include "../functions/scan_nmrplade.h"
#include "../functions/simulering.h"

TEST_CASE(test_afstand, {
    int result = 0;
    PriorityQueue afstandHeap = { .size = 0 };
    PriorityQueue tidHeap = { .size = 0 };
    PriorityQueue ledighedHeap = { .size = 0 };
    Parkeringsplads pladser[500];
    int antalPladser = 0;
    læsDataFraFil("test_datafil.txt", &afstandHeap, &tidHeap, &ledighedHeap, pladser, &antalPladser, 0, 0);
    while (afstandHeap.size > 0) {
                    HeapNode bedsteAfstand = extractMax(&afstandHeap);
                    if (bedsteAfstand.plads.handicap == 0 && bedsteAfstand.plads.el == 0 && bedsteAfstand.plads.ledighed == 0) {
                        printf("Bedste plads baseret på afstand: Plads %d med afstand %.2f meter\n",
                               bedsteAfstand.plads.nummer, bedsteAfstand.plads.distance);
                        result = bedsteAfstand.plads.nummer;
                        break;
                    }
                }
    CHECK_EQ_INT(136, result);
})


TEST_CASE(test_tid, {
    int result = 0;
    PriorityQueue afstandHeap = { .size = 0 };
    PriorityQueue tidHeap = { .size = 0 };
    PriorityQueue ledighedHeap = { .size = 0 };
    Parkeringsplads pladser[500];
    int antalPladser = 0;
    læsDataFraFil("test_datafil.txt", &afstandHeap, &tidHeap, &ledighedHeap, pladser, &antalPladser, 0, 0);
    while (tidHeap.size > 0) {
        HeapNode bedsteTid = extractMax(&tidHeap);
            if (bedsteTid.plads.handicap == 0 && bedsteTid.plads.el == 0 && bedsteTid.plads.ledighed == 0) {
                printf("Bedste plads baseret på tid: Plads %d med tid %d sekunder\n",
                bedsteTid.plads.nummer, bedsteTid.plads.tid);
                result = bedsteTid.plads.nummer;
                break;
    }
}
CHECK_EQ_INT(15, result);
})


TEST_CASE(test_ledighed, {
    int result = 0;
    PriorityQueue afstandHeap = { .size = 0 };
    PriorityQueue tidHeap = { .size = 0 };
    PriorityQueue ledighedHeap = { .size = 0 };
    Parkeringsplads pladser[500];
    int antalPladser = 0;
    læsDataFraFil("test_datafil.txt", &afstandHeap, &tidHeap, &ledighedHeap, pladser, &antalPladser, 0, 0);
    while (ledighedHeap.size > 0) {
        HeapNode bedsteLedighed = extractMax(&ledighedHeap);
            if (bedsteLedighed.plads.handicap == 0 && bedsteLedighed.plads.el == 0 && bedsteLedighed.plads.ledighed == 0) {
                printf("Bedste plads baseret på ledighed: Plads %d med ledighed %d (lavere er bedre)\n",
                bedsteLedighed.plads.nummer, bedsteLedighed.plads.ledighed);
                result = bedsteLedighed.plads.nummer;
                break;
            }
    }
    CHECK_EQ_INT(15, result);
})

MAIN_RUN_TESTS(test_afstand, test_ledighed, test_tid)