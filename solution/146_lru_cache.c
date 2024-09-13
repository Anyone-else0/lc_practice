/*
 * @lc app=leetcode.cn id=146 lang=c
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include "pea_hash_table.h"
#include "pea_list.h"
/*
typedef struct {
    int cap;
    int nr;
    PeaListHead_t head;
    PeaHashTable_t *pTable;
} LRUCache;

typedef struct LruKey {
    int k;
} LruKey_t;

typedef struct LruVal {
    int v;
    PeaListHead_t node;
} LruVal_t;

typedef struct LruEntry {
    LruKey_t key;
    LruVal_t val;
} LruEntry_t;

static void lRUKvInit(PeaHashKv_t *pKv, LruEntry_t *pEntry)
{
    pKv->keyLen = sizeof(pEntry->key);
    pKv->pKey = &pEntry->key;
    pKv->valueLen = sizeof(pEntry->val);
    pKv->pValue = &pEntry->val;
    return;
}

LRUCache *lRUCacheCreate(int capacity)
{
    LRUCache *pLru = (LRUCache *)malloc(sizeof(*pLru));
    peaListNodeInit(&pLru->head);
    pLru->pTable = peaHashTableCreate(2000);
    pLru->cap = capacity;
    pLru->nr = 0;
    return pLru;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    PeaHashTable_t *pTable = obj->pTable;
    PeaHashKv_t kv;
    LruEntry_t entry;
    lRUKvInit(&kv, &entry);
    entry.key.k = key;
    if (pTable->pfKvGet(pTable, &kv) != 0) {
        entry.val.v = -1;
    }

    return entry.val.v;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    PeaHashTable_t *pTable = obj->pTable;
    PeaHashKv_t kv;
    LruEntry_t entry;
    lRUKvInit(&kv, &entry);
    entry.key.k = key;
    if (pTable->pfKvGet(pTable, &kv) != 0 && obj->nr == obj->cap) {
        PeaListHead_t *pNode = peaListPickTail(&obj->head);
        LruVal_t *pVal = PEA_LIST_ENTRY(pNode, LruVal_t, node);
        LruEntry_t *pEntry = PEA_LIST_ENTRY(pVal, LruEntry_t, val);
        lRUKvInit(&kv, pEntry);
        (void)pTable->pfKvPick(pTable, &kv);
    }

    hsVal.val = -1;
    (void)pTable->pfKvPut(pTable, &kv);

    return;
}

void lRUCacheFree(LRUCache* obj)
{
    
    return;
}*/

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
// @lc code=end

