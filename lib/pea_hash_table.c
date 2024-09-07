#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pea_hash_table.h"

typedef struct PeaHashNode {
    struct PeaHashNode *pNext;
    PeaHashKv_t kv;
} PeaHashNode_t;

static PeaHashNode_t *peaHashTableNodeMalloc(int keyLen, int valueLen)
{
    PeaHashNode_t *pNode = malloc(sizeof(*pNode) + keyLen + valueLen);
    if (pNode == NULL) {
        printf("[ERROR]Hash node malloc failed.\n");
        goto l_end;
    }
    pNode->kv.pKey = &pNode->kv.pad[0];
    pNode->kv.keyLen = keyLen;
    pNode->kv.pValue = &pNode->kv.pad[keyLen];
    pNode->kv.valueLen = valueLen;
    pNode->pNext = NULL;

l_end:
    return pNode;
}

static void peaHashTableNodeFree(PeaHashNode_t *pNode)
{
    free(pNode);
}

static int peaHashTableGetBucketIdx(PeaHashTable_t *pTable, void *pKey, int keyLen)
{
    int idx = 0;
    unsigned char *tmpKey = pKey;
    for (int i = 0; i < keyLen; i++) {
        idx += (int)(*tmpKey);
        tmpKey++;
    }
    idx = abs(idx);
    idx %= pTable->bucketCap;
    return idx;
}

static PeaHashNode_t *peaHashTableKvFind(PeaHashTable_t *pTable, void *pKey, int keyLen, PeaHashNode_t **ppLastNode)
{
    int bucketIdx = peaHashTableGetBucketIdx(pTable, pKey, keyLen);
    PeaHashNode_t *pTmpNode = (PeaHashNode_t *)pTable->ppBucket[bucketIdx];
    PeaHashNode_t *pLastNode = NULL;
    while (pTmpNode != NULL) {
        int cmpRc = memcmp(pTmpNode->kv.pKey, pKey, keyLen);
        if (cmpRc == 0)
        {
            break;
        } else if (cmpRc > 0) {
            pTmpNode = NULL;
            break;
        } else {
            pLastNode = pTmpNode;
            pTmpNode = pTmpNode->pNext;
        }
    }

    if (ppLastNode != NULL) {
        *ppLastNode = pLastNode;
    }

    return pTmpNode;
}

static int peaHashTableKvGet(PeaHashTable_t *pTable, PeaHashKv_t *pKv)
{
    int rc = -1;
    PeaHashNode_t *pTmpNode = peaHashTableKvFind(pTable, pKv->pKey, pKv->keyLen, NULL);
    if (pTmpNode != NULL) {
        (void)memcpy(pKv->pValue, pTmpNode->kv.pValue, pTmpNode->kv.valueLen);
        pKv->valueLen = pTmpNode->kv.valueLen;
        rc = 0;
    }

    return rc;
}

static int peaHashTableKvPick(PeaHashTable_t *pTable, PeaHashKv_t *pKv)
{
    int rc = -1;
    PeaHashNode_t *pLastNode = NULL;
    PeaHashNode_t *pTmpNode = peaHashTableKvFind(pTable, pKv->pKey, pKv->keyLen, &pLastNode);
    if (pTmpNode != NULL) {
        (void)memcpy(pKv->pValue, pTmpNode->kv.pValue, pTmpNode->kv.valueLen);
        pKv->valueLen = pTmpNode->kv.valueLen;
        rc = 0;
        if (pLastNode != NULL) {
            pLastNode->pNext = pTmpNode->pNext;
        } else {
            pTable->ppBucket[peaHashTableGetBucketIdx(pTable, pKv->pKey, pKv->keyLen)] = pTmpNode->pNext;
        }
        free(pTmpNode);
    }

    return rc;
}

static int peaHashTableKvPut(PeaHashTable_t *pTable, PeaHashKv_t *pKv)
{
    int rc = 0;
    PeaHashNode_t *pLastNode = NULL;
    PeaHashNode_t *pTmpNode = peaHashTableKvFind(pTable, pKv->pKey, pKv->keyLen, &pLastNode);
    if (pTmpNode != NULL) {
        (void)memcpy(pTmpNode->kv.pValue, pKv->pValue, pKv->valueLen);
        goto l_end;
    } else {
        PeaHashNode_t *pNewNode = peaHashTableNodeMalloc(pKv->keyLen, pKv->valueLen);
        if (pNewNode == NULL) {
            rc = -1;
            goto l_end;
        }
        (void)memcpy(pNewNode->kv.pKey, pKv->pKey, pKv->keyLen);
        (void)memcpy(pNewNode->kv.pValue, pKv->pValue, pKv->valueLen);
        if (pLastNode != NULL) {
            pNewNode->pNext = pLastNode->pNext;
            pLastNode->pNext = pNewNode;
        } else {
            int bucketIdx = peaHashTableGetBucketIdx(pTable, pKv->pKey, pKv->keyLen);
            pNewNode->pNext = pTable->ppBucket[bucketIdx];
            pTable->ppBucket[bucketIdx] = pNewNode;
        }
    }

l_end:
    return rc;
}

static void peaHashTableDestroy(PeaHashTable_t *pTable)
{
    PeaHashNode_t *pTmpNode;
    for (int idx = 0; idx < pTable->bucketCap; idx++) {
        while (pTable->ppBucket[idx] != NULL) {
            pTmpNode = (PeaHashNode_t *)pTable->ppBucket[idx];
            pTable->ppBucket[idx] = pTmpNode->pNext;
            peaHashTableNodeFree(pTmpNode);
        }
    }
    free(pTable->ppBucket);
    free(pTable);
}

PeaHashTable_t *peaHashTableCreate(int bucketCap)
{
    PeaHashTable_t *pHashTable = (PeaHashTable_t *)malloc(sizeof(*pHashTable));
    if (pHashTable == NULL) {
        printf("[ERROR]Hash table malloc failed.\n");
        goto l_end;
    }
    pHashTable->bucketCap = bucketCap;
    pHashTable->ppBucket = malloc(sizeof(*pHashTable->ppBucket) * bucketCap);
    if (pHashTable->ppBucket == NULL) {
        free(pHashTable);
        pHashTable = NULL;
        printf("[ERROR]Hash bicket malloc failed.\n");
        goto l_end;
    }
    memset(pHashTable->ppBucket, 0, sizeof(*pHashTable->ppBucket) * bucketCap);
    pHashTable->pfDestroy = peaHashTableDestroy;
    pHashTable->pfKvGet = peaHashTableKvGet;
    pHashTable->pfKvPick = peaHashTableKvPick;
    pHashTable->pfKvPut = peaHashTableKvPut;

l_end:
    return pHashTable;
}