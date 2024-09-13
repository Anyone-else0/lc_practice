#ifndef __146_LRU_CACHE_H__
#define __146_LRU_CACHE_H__

typedef struct {
    int cap;
    PeaListHead_t head;
    PeaHashTable_t *pTable;
} LRUCache;

LRUCache *lRUCacheCreate(int capacity);
int lRUCacheGet(LRUCache* obj, int key);
void lRUCachePut(LRUCache* obj, int key, int value);
void lRUCacheFree(LRUCache* obj);

#endif