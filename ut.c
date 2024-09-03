#include <stdio.h>
#include <time.h>
#include "ut.h"
#include "ut_def.h"
#include "pea_hash_table_ut.h"
#include "pea_stack_ut.h"
#include "pea_queue_ut.h"
#include "pea_sort_ut.h"
#include "pea_lc_practice_ut.h"

UtStats_t gUtStats = {0};

UtSuit_t utSuits[] = {
    {"hash_table_suit", gPeaHashTableSuit},
    {"stack_suit", gPeaStackSuit},
    {"queue_suit", gPeaQueueSuit},
    {"sort_suit", gPeaSortSuit},
    {"lc_practice_suit", gPeaLcPracticeSuit},
};

int utRun(void)
{
    for (int suitIdx = 0; suitIdx < sizeof(utSuits) / sizeof(utSuits[0]); suitIdx++) {
        printf("[UTSuit] begin: %s\n", utSuits[suitIdx].pName);
        int caseIdx = 0;
        while (utSuits[suitIdx].pUtCase[caseIdx].pUtTest != NULL)
        {
            printf("    Enter Case: %s\n", utSuits[suitIdx].pUtCase[caseIdx].pName);
            clock_t start_t = clock();
            utSuits[suitIdx].pUtCase[caseIdx].pUtTest();
            clock_t total_t = clock() - start_t;
            printf("    Exit Case : %s, %ldus\n", utSuits[suitIdx].pUtCase[caseIdx].pName, total_t);
            caseIdx++;
        }
        printf("[UTSuit] end  : %s\n\n", utSuits[suitIdx].pName);
    }
    printf("[UTStats] begin\n");
    printf("    |     total|      succ|      fail|\n");
    printf("    |%10d|%10d|%10d|\n", gUtStats.total, gUtStats.succ, gUtStats.fail);
    printf("[UTStats] end\n");
    printf("\n");

    return 0;
}
