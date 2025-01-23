/*
 * @lc app=leetcode.cn id=460 lang=c
 *
 * [460] LFU 缓存
 */

// @lc code=start
#include "pea_list.h"
#include "pea_hash_table.h"
#include <stdlib.h>
/*
typedef struct {
    int cap;
    int nr;
    PeaListHead_t head;
    PeaHashTable_t *pTable;
} LFUCache;

typedef struct CacheKv {
    int key;
    int value;
    int freq;
    PeaListHead_t head;
} CacheKv_t;

static int cacheKeyCmp(void *pKey1, void *pKey2)
{
    return *(int *)pKey1 - *(int *)pKey2;
}

static void *cacheGetKey(void *pKv)
{
    CacheKv_t *pCacheKv = (CacheKv_t *)pKv;
    return &pCacheKv->key;
}

static int cacheGetIdx(void *pKey)
{
    return abs(*(int *)pKey);
}

LFUCache *lFUCacheCreate(int capacity)
{
    LFUCache *pCache = (LFUCache *)malloc(sizeof(LFUCache));
    pCache->cap = capacity;
    pCache->nr = 0;
    peaListNodeInit(&pCache->head);
    pCache->pTable = peaHashTableCreate(
        pCache->cap,
        cacheKeyCmp,
        cacheGetIdx,
        cacheGetKey);
    return pCache;
}

void lFUCacheNodeAdd(LFUCache* obj, PeaListHead_t *pNode, PeaListHead_t *pNodeNext)
{
    PeaListHead_t *pNext = pNodeNext;
    CacheKv_t *pKv = PEA_LIST_ENTRY(pNode, CacheKv_t, head);
    PeaListHead_t *pPrev = obj->head.pPrev;
    int flag = 0;

    while (pNext != &obj->head) {
        CacheKv_t *pNextKv =  PEA_LIST_ENTRY(pNext, CacheKv_t, head);
        if (pKv->freq < pNextKv->freq) {
            flag = 1;
            break;
        }
        pNext = pNext->pNext;
        CacheKv_t *pPrevKv = PEA_LIST_ENTRY(pPrev, CacheKv_t, head);
        if (pKv->freq >= pPrevKv->freq) {
            flag = 2;
            break;
        } 
        pPrev = pPrev->pPrev;
    }
    if (flag == 2) {
        peaListAdd(pNode, pPrev, pPrev->pNext);
    } else {
        peaListAdd(pNode, pNext->pPrev, pNext);
    }

    return;
}

int lFUCacheGet(LFUCache* obj, int key)
{
    CacheKv_t *pKv = obj->pTable->pfKvGet(obj->pTable, &key);
    if (pKv == NULL) {
        return -1;
    }
    pKv->freq++;
    
    PeaListHead_t *pNodeNext = pKv->head.pNext;
    peaListDel(&pKv->head);
    lFUCacheNodeAdd(obj, &pKv->head, pNodeNext);

    return pKv->value;
}

void lFUCachePut(LFUCache* obj, int key, int value)
{
    CacheKv_t *pKv = obj->pTable->pfKvGet(obj->pTable, &key);
    if (pKv != NULL) {
        pKv->value = value;
        pKv->freq++;
        PeaListHead_t *pNodeNext = pKv->head.pNext;
        peaListDel(&pKv->head);
        lFUCacheNodeAdd(obj, &pKv->head, pNodeNext);
    } else if (obj->cap == obj->nr) {
        PeaListHead_t *pLastNode = peaListPickTail(&obj->head);
        pKv = PEA_LIST_ENTRY(pLastNode, CacheKv_t, head);
        pKv = obj->pTable->pfKvPick(obj->pTable, &pKv->key);
        pKv->key = key;
        pKv->value = value;
        pKv->freq = 1;
        (void)obj->pTable->pfKvPut(obj->pTable, pKv);
        lFUCacheNodeAdd(obj, &pKv->head, obj->head.pNext);
    } else {
        pKv = (CacheKv_t *)malloc(sizeof(*pKv));
        pKv->key = key;
        pKv->value = value;
        pKv->freq = 1;
        lFUCacheNodeAdd(obj, &pKv->head, obj->head.pNext);
        (void)obj->pTable->pfKvPut(obj->pTable, pKv);
        obj->nr++;
    }
    return;
}

void lFUCacheFree(LFUCache* obj)
{
    obj->pTable->pfDestroy(obj->pTable);
    free(obj);
}
*/

typedef struct {
    int cap;
    int nr;
    PeaHashTable_t *pIdxTable;
    PeaHashTable_t *pFreqTable;
    int minFreq;
} LFUCache;

typedef struct CacheKv {
    int key;
    int freq;
    int value;
    PeaListHead_t freqHead;
} CacheKv_t;

typedef struct CacheFreqListKv {
    int freq;
    PeaListHead_t kvList;
} CacheFreqListKv_t;

static int cacheIdxKeyCmp(void *pKey1, void *pKey2)
{
    return *(int *)pKey1 - *(int *)pKey2;
}

static void *cacheIdxGetKey(void *pKv)
{
    CacheKv_t *pCacheKv = (CacheKv_t *)pKv;
    return &pCacheKv->key;
}

static int cacheIdxGetIdx(void *pKey)
{
    return abs(*(int *)pKey);
}

static int cacheFreqKeyCmp(void *pKey1, void *pKey2)
{
    return *(int *)pKey1 - *(int *)pKey2;
}

static void *cacheFreqGetKey(void *pKv)
{
    CacheFreqListKv_t *pCacheFreqKv = (CacheFreqListKv_t *)pKv;
    return &pCacheFreqKv->freq;
}

static int cacheFreqGetIdx(void *pKey)
{
    return abs(*(int *)pKey);
}

LFUCache *lFUCacheCreate(int capacity)
{
    LFUCache *pCache = (LFUCache *)malloc(sizeof(LFUCache));
    pCache->cap = capacity;
    pCache->nr = 0;
    pCache->pIdxTable = peaHashTableCreate(
        pCache->cap,
        cacheIdxKeyCmp,
        cacheIdxGetIdx,
        cacheIdxGetKey);
    pCache->pFreqTable = peaHashTableCreate(
        pCache->cap,
        cacheFreqKeyCmp,
        cacheFreqGetIdx,
        cacheFreqGetKey);
    pCache->minFreq = 0;
    return pCache;
}

static void lFUCacheFreqChg(LFUCache* obj, CacheKv_t *pKv, int newFreq)
{
    CacheFreqListKv_t *pOldFreqKv = obj->pFreqTable->pfKvGet(obj->pFreqTable, &pKv->freq);
    peaListDel(&pKv->freqHead);
    peaListNodeInit(&pKv->freqHead);

    if (peaListEmpty(&pOldFreqKv->kvList)) {
        obj->pFreqTable->pfKvPick(obj->pFreqTable, &pOldFreqKv->freq);
        free(pOldFreqKv);
        if (obj->minFreq == pKv->freq) {
            obj->minFreq = newFreq;
        }
    }

    pKv->freq = newFreq;
    CacheFreqListKv_t *pFreqKv = obj->pFreqTable->pfKvGet(obj->pFreqTable, &pKv->freq);
    if (pFreqKv == NULL) {
        pFreqKv = (CacheFreqListKv_t *)malloc(sizeof(*pFreqKv));
        pFreqKv->freq = pKv->freq;
        peaListNodeInit(&pFreqKv->kvList);
        obj->pFreqTable->pfKvPut(obj->pFreqTable, pFreqKv);
    }
    peaListAddTail(&pFreqKv->kvList, &pKv->freqHead);
    return;
}

int lFUCacheGet(LFUCache* obj, int key)
{
    CacheKv_t *pKv = obj->pIdxTable->pfKvGet(obj->pIdxTable, &key);
    if (pKv == NULL) {
        return -1;
    }
    lFUCacheFreqChg(obj, pKv, pKv->freq + 1);
    return pKv->value;
}

static void lFUCachePutNew(LFUCache* obj, int key, int value)
{
    CacheKv_t *pIdxKv = (CacheKv_t *)malloc(sizeof(*pIdxKv));
    pIdxKv->freq = 1;
    pIdxKv->key = key;
    pIdxKv->value = value;
    peaListNodeInit(&pIdxKv->freqHead);
    obj->pIdxTable->pfKvPut(obj->pIdxTable, pIdxKv);
    obj->nr++;
    obj->minFreq = 1;

    CacheFreqListKv_t *pFreqKv = obj->pFreqTable->pfKvGet(obj->pFreqTable, &pIdxKv->freq);
    if (pFreqKv == NULL) {
        pFreqKv = (CacheFreqListKv_t *)malloc(sizeof(*pFreqKv));
        peaListNodeInit(&pFreqKv->kvList);
        pFreqKv->freq = pIdxKv->freq;
        obj->pFreqTable->pfKvPut(obj->pFreqTable, pFreqKv);
    }
    peaListAddTail(&pFreqKv->kvList, &pIdxKv->freqHead);
}

void lFUCachePut(LFUCache* obj, int key, int value)
{
    CacheKv_t *pKv = obj->pIdxTable->pfKvGet(obj->pIdxTable, &key);
    if (pKv != NULL) {
        pKv->value = value;
        lFUCacheFreqChg(obj, pKv, pKv->freq + 1);
    } else if (obj->cap == obj->nr) {
        CacheFreqListKv_t *pLeastFreqKv = obj->pFreqTable->pfKvGet(obj->pFreqTable, &obj->minFreq);
        PeaListHead_t *pIdxKvNode = peaListPickHead(&pLeastFreqKv->kvList);
        if (peaListEmpty(&pLeastFreqKv->kvList)) {
            obj->pFreqTable->pfKvPick(obj->pFreqTable, &pLeastFreqKv->freq);
            free(pLeastFreqKv);
        }
        CacheKv_t *pKv = PEA_LIST_ENTRY(pIdxKvNode, CacheKv_t, freqHead);
        obj->pIdxTable->pfKvPick(obj->pIdxTable, &pKv->key);
        free(pKv);
        obj->nr--;
        lFUCachePutNew(obj, key, value);
    } else {
        lFUCachePutNew(obj, key, value);
    }
    return;
}

void lFUCacheFree(LFUCache* obj)
{
    obj->pIdxTable->pfDestroy(obj->pIdxTable);
    obj->pFreqTable->pfDestroy(obj->pFreqTable);
    free(obj);
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/
// @lc code=end

