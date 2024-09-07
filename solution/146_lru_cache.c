/*
 * @lc app=leetcode.cn id=146 lang=c
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include "pea_hash_table.h"
#include "pea_list.h"

typedef struct {
    int cap;
    PeaListNode_t head;
    PeaHashTable_t *pTable;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity)
{
    return NULL;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    return 0;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    
}

void lRUCacheFree(LRUCache* obj)
{
    
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
// @lc code=end

