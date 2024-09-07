#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pea_hash_table_ut.h"
#include "pea_hash_table.h"

#define PEA_HASH_BUCKET_CAP (10)

typedef struct PeaUtHashKey {
    int num;
} PeaUtHashKey_t;

typedef struct PeaHtHashValue {
    int value;
} PeaUtHashValue_t;

static void peaHashLsitTableTest(void)
{
    PeaUtHashKey_t *pTmpKey = NULL;
    PeaUtHashValue_t *pTmpValue = NULL;

    PeaHashTable_t *pTable = peaHashTableCreate(PEA_HASH_BUCKET_CAP);
    UT_ASSERT(pTable != NULL);
    PeaHashKv_t *pTmpKv = (PeaHashKv_t *)malloc(sizeof(*pTmpKv) + sizeof(*pTmpKey) + sizeof(*pTmpValue));
    UT_ASSERT(pTmpKv != NULL);
    pTmpKv->keyLen = sizeof(*pTmpKey);
    pTmpKv->valueLen = sizeof(*pTmpValue);
    pTmpKv->pKey = &pTmpKv->pad[0];
    pTmpKv->pValue = &pTmpKv->pad[pTmpKv->keyLen];
    pTmpKey = (PeaUtHashKey_t *)pTmpKv->pKey;
    pTmpValue = (PeaUtHashValue_t *)pTmpKv->pValue;

    {
        int kvNum = 2001;
        for (int idx = 0; idx < kvNum; idx++) {
            pTmpKey->num = idx;
            pTmpValue->value = pTmpKey->num;
            int rc = pTable->pfKvPut(pTable, pTmpKv);
            UT_ASSERT(rc == 0);
        }
        for (int idx = 0; idx < kvNum; idx++)
        {
            pTmpKey->num = idx;
            int rc = pTable->pfKvGet(pTable, pTmpKv);
            UT_ASSERT(rc == 0);
            UT_ASSERT(pTmpValue->value == pTmpKey->num);
        }
        for (int idx = 0; idx < kvNum; idx++)
        {
            pTmpKey->num = idx;
            int rc = pTable->pfKvPick(pTable, pTmpKv);
            UT_ASSERT(rc == 0);
            UT_ASSERT(pTmpValue->value == pTmpKey->num);
        }
        for (int idx = 0; idx < pTable->bucketCap; idx++)
        {
            UT_ASSERT(pTable->ppBucket[idx] == NULL);
        }
    }
    pTable->pfDestroy(pTable);
    free(pTmpKv);
}

UtCase_t gPeaHashTableSuit[] = {
    {"peaHashLsitTableTest", peaHashLsitTableTest},
    {NULL, NULL}
};
