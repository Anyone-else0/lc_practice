/*
 * @lc app=leetcode.cn id=460 lang=c
 *
 * [460] LFU 缓存
 */

// @lc code=start
#include "pea_list.h"
#include "pea_hash_table.h"
#include <stdlib.h>

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

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/
// @lc code=end

