/*
 * @lc app=leetcode.cn id=142 lang=c
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include "pea_hash_table.h"

#define HASH_BUCKET_SIZE 1024

typedef struct Entry_s
{
    struct ListNode *pNode;
} Kv_t;

static int listNodeCmp(void *pKey1, void *pKey2)
{
    struct ListNode **pNode1 = (struct ListNode **)pKey1;
    struct ListNode **pNode2 = (struct ListNode **)pKey2;
    return (size_t)(*pNode1) - (size_t)(*pNode2);
}

static int listNodeGetIdx(void *pKey)
{
    struct ListNode **pNode = (struct ListNode **)pKey;
    return (size_t)(*pNode) % HASH_BUCKET_SIZE;
}

static void *listNodeGetKey(void *pKv)
{
    Kv_t *pEntry = (Kv_t *)pKv;
    return (void *)&pEntry->pNode;
}

struct ListNode *detectCycle(struct ListNode *head)
{
    PeaHashTable_t *pHashTable = peaHashTableCreate(HASH_BUCKET_SIZE, listNodeCmp, listNodeGetIdx, listNodeGetKey);
    struct ListNode *pNode = head;
    while (pNode != NULL) {
        if (pHashTable->pfKvGet(pHashTable, &pNode) != NULL) {
            break;
        }
        Kv_t *pKv = (Kv_t *)malloc(sizeof(*pKv));
        pKv->pNode = pNode;
        pHashTable->pfKvPut(pHashTable, pKv);
        pNode = pNode->next;
    }
    pHashTable->pfDestroy(pHashTable);
    return pNode;
}
// @lc code=end

