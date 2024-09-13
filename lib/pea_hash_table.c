#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pea_hash_table.h"

typedef struct PeaHashEntry {
    struct PeaHashEntry *pNext;
    void *pKv;
} PeaHashEntry_t;

typedef struct PeaHashPriv {
    int bucketCap;
    void **ppBucket;
    int (*pfKeyCmp)(void *pKey1, void *pKey2);
    int (*pfGetIdx)(void *pKey);
    void *(*pfGetKey)(void *pKv);
} PeaHashPriv_t;

static PeaHashEntry_t *peaHashTableKvFind(PeaHashTable_t *pTable, void *pKey, PeaHashEntry_t **ppLastEntry)
{
    int bucketIdx = pTable->pPriv->pfGetIdx(pKey) % pTable->pPriv->bucketCap;
    PeaHashEntry_t *pTmpEntry = (PeaHashEntry_t *)pTable->pPriv->ppBucket[bucketIdx];
    PeaHashEntry_t *pLastEntry = NULL;
    while (pTmpEntry != NULL) {
        int cmpRc = pTable->pPriv->pfKeyCmp(pTable->pPriv->pfGetKey(pTmpEntry->pKv), pKey);
        if (cmpRc == 0)
        {
            break;
        } else if (cmpRc > 0) {
            pTmpEntry = NULL;
            break;
        } else {
            pLastEntry = pTmpEntry;
            pTmpEntry = pTmpEntry->pNext;
        }
    }

    if (ppLastEntry != NULL) {
        *ppLastEntry = pLastEntry;
    }

    return pTmpEntry;
}

static void *peaHashTableKvGet(PeaHashTable_t *pTable, void *pKey)
{
    void *pKv = NULL;
    PeaHashEntry_t *pTmpEntry = peaHashTableKvFind(pTable, pKey, NULL);
    if (pTmpEntry != NULL) {
        pKv = pTmpEntry->pKv;
    }

    return pKv;
}

static void *peaHashTableKvPick(PeaHashTable_t *pTable, void *pKey)
{
    void *pKv = NULL;
    PeaHashEntry_t *pLastEntry = NULL;
    PeaHashEntry_t *pTmpEntry = peaHashTableKvFind(pTable, pKey, &pLastEntry);
    if (pTmpEntry != NULL) {
        pKv = pTmpEntry->pKv;
        if (pLastEntry != NULL) {
            pLastEntry->pNext = pTmpEntry->pNext;
        } else {
            pTable->pPriv->ppBucket[pTable->pPriv->pfGetIdx(pKey) % pTable->pPriv->bucketCap] = pTmpEntry->pNext;
        }
        free(pTmpEntry);
    }

    return pKv;
}

static int peaHashTableKvPut(PeaHashTable_t *pTable, void *pKv)
{
    int rc = 0;
    void *pKey = pTable->pPriv->pfGetKey(pKv);
    PeaHashEntry_t *pLastEntry = NULL;
    PeaHashEntry_t *pTmpEntry = peaHashTableKvFind(pTable, pKey, &pLastEntry);
    if (pTmpEntry != NULL) {
        rc = -1;
        goto l_end;
    } else {
        PeaHashEntry_t *pNewEntry = (PeaHashEntry_t *)malloc(sizeof(*pNewEntry));
        if (pNewEntry == NULL) {
            rc = -1;
            goto l_end;
        }
        pNewEntry->pKv = pKv;
        if (pLastEntry != NULL) {
            pNewEntry->pNext = pLastEntry->pNext;
            pLastEntry->pNext = pNewEntry;
        } else {
            int bucketIdx = pTable->pPriv->pfGetIdx(pKey) % pTable->pPriv->bucketCap;
            pNewEntry->pNext = pTable->pPriv->ppBucket[bucketIdx];
            pTable->pPriv->ppBucket[bucketIdx] = pNewEntry;
        }
    }

l_end:
    return rc;
}

static void peaHashTableDestroy(PeaHashTable_t *pTable)
{
    if (pTable != NULL) {
        for (int idx = 0; idx < pTable->pPriv->bucketCap; idx++) {
            while (pTable->pPriv->ppBucket[idx] != NULL) {
                PeaHashEntry_t *pTmpEntry = (PeaHashEntry_t *)pTable->pPriv->ppBucket[idx];
                pTable->pPriv->ppBucket[idx] = pTmpEntry->pNext;
                free(pTmpEntry->pKv);
                free(pTmpEntry);
            }
        }
        if (pTable->pPriv->ppBucket != NULL) {
            free(pTable->pPriv->ppBucket);
        }
        if (pTable->pPriv != NULL) {
            free(pTable->pPriv);
        }
        free(pTable);
    }
    return;
}

PeaHashTable_t *peaHashTableCreate(
    int bucketCap,
    int (*pfKeyCmp)(void *pKv1, void *pKv2),
    int (*pfGetIdx)(void *pKv),
    void *(pfGetKey)(void *pKv))
{
    PeaHashTable_t *pTable = (PeaHashTable_t *)malloc(sizeof(*pTable));
    if (pTable == NULL) {
        printf("[ERROR]Hash table malloc failed.\n");
        goto l_fail;
    }

    pTable->pPriv = (PeaHashPriv_t *)malloc(sizeof(*pTable->pPriv));
    if (pTable == NULL) {
        printf("[ERROR]Hash table priv malloc failed.\n");
        goto l_fail;
    }

    pTable->pPriv->bucketCap = bucketCap;
    pTable->pPriv->ppBucket = malloc(sizeof(*pTable->pPriv->ppBucket) * pTable->pPriv->bucketCap);
    if (pTable->pPriv->ppBucket == NULL) {
        printf("[ERROR]Hash bicket malloc failed.\n");
        goto l_fail;
    }
    memset(pTable->pPriv->ppBucket, 0, sizeof(*pTable->pPriv->ppBucket) * pTable->pPriv->bucketCap);
    pTable->pfDestroy = peaHashTableDestroy;
    pTable->pfKvGet = peaHashTableKvGet;
    pTable->pfKvPick = peaHashTableKvPick;
    pTable->pfKvPut = peaHashTableKvPut;
    pTable->pPriv->pfKeyCmp = pfKeyCmp;
    pTable->pPriv->pfGetIdx = pfGetIdx;
    pTable->pPriv->pfGetKey = pfGetKey;
    goto l_end;

l_fail:
    peaHashTableDestroy(pTable);
    pTable = NULL;

l_end:
    return pTable;
}