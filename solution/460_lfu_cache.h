#ifndef __460_LFU_CACHE_H__
#define __460_LFU_CACHE_H__

typedef struct {
    int cap;
    int nr;
    PeaHashTable_t *pIdxTable;
    PeaHashTable_t *pFreqTable;
    PeaListHead_t sortList;
} LFUCache;

LFUCache* lFUCacheCreate(int capacity);

int lFUCacheGet(LFUCache* obj, int key);

void lFUCachePut(LFUCache* obj, int key, int value);

void lFUCacheFree(LFUCache* obj);

#endif