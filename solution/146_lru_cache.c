/*
 * @lc app=leetcode.cn id=146 lang=c
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <stdlib.h>
#include "pea_hash_table.h"
#include "pea_list.h"

typedef struct LRUCache_s
{
    int cap;
    int nr;
    PeaListHead_t head;
    PeaHashTable_t *pTable;
} LRUCache;

typedef struct LruKv {
    int k;
    int v;
    PeaListHead_t node;
} LruKv_t;

static int lruKeyCmp(void *key1, void *key2)
{
    return *(int *)key1 - *(int *)key2;
}

static int lruGetIdx(void *pKey)
{
    return abs(*(int *)pKey);
}

static void *lurGetKey(void *pKv)
{
    return (void *)(&((LruKv_t *)pKv)->k);
}

LRUCache *lRUCacheCreate(int capacity)
{
    LRUCache *pLru = (LRUCache *)malloc(sizeof(*pLru));
    peaListNodeInit(&pLru->head);
    pLru->pTable = peaHashTableCreate(2000, lruKeyCmp, lruGetIdx, lurGetKey);
    pLru->cap = capacity;
    pLru->nr = 0;
    return pLru;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    int rc = -1;
    PeaHashTable_t *pTable = obj->pTable;
    LruKv_t *pKv = pTable->pfKvGet(pTable, &key);
    if (pKv != NULL) {
        rc = pKv->v;
        peaListDel(&pKv->node);
        peaListAddHead(&obj->head, &pKv->node);
    }

    return rc;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    PeaHashTable_t *pTable = obj->pTable;

    LruKv_t *pKv = pTable->pfKvGet(pTable, &key);
    if (pKv != NULL) {
        pKv->v = value;
        peaListDel(&pKv->node);
        peaListAddHead(&obj->head, &pKv->node);
    } else if (obj->nr == obj->cap) {
        PeaListHead_t *pLastNode = peaListPickTail(&obj->head);
        pKv = PEA_LIST_ENTRY(pLastNode, LruKv_t, node);
        pKv = pTable->pfKvPick(pTable, &pKv->k);
        pKv->k = key;
        pKv->v = value;
        (void)pTable->pfKvPut(pTable, pKv);
        peaListAddHead(&obj->head, &pKv->node);
    } else {
        pKv = (LruKv_t *)malloc(sizeof(*pKv));
        pKv->k = key;
        pKv->v = value;
        peaListAddHead(&obj->head, &pKv->node);
        (void)pTable->pfKvPut(pTable, pKv);
        obj->nr++;
    }

    return;
}

void lRUCacheFree(LRUCache* obj)
{
    if (obj != NULL) {
        if (obj->pTable != NULL) {
            obj->pTable->pfDestroy(obj->pTable);
        }
        free(obj);
    }
    return;
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
// @lc code=end

