#ifndef __UT_TYPE_H__
#define __UT_TYPE_H__

#include <stdio.h>
#include <stdbool.h>

typedef struct UtStats {
    int total;
    int succ;
    int fail;
} UtStats_t;

extern UtStats_t gUtStats;

#define UT_ASSERT(cond)                                                             \
do {                                                                                \
    gUtStats.total++;                                                               \
    if ((cond) == false) {                                                          \
        gUtStats.fail++;                                                            \
        printf("["__FILE__": %d][%s]: Ut assert failed! cond: %s\n",                \
        __LINE__, __func__, #cond);                                                 \
    } else {                                                                        \
        gUtStats.succ++;                                                            \
    }                                                                               \
} while (0)                                                                         \

typedef void (UtTest_t)(void);

typedef struct UtCase {
    char *pName;
    UtTest_t *pUtTest;
} UtCase_t;

typedef struct UtSuit {
    char *pName;
    UtCase_t *pUtCase;
} UtSuit_t;

#endif