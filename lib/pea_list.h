#ifndef __PEA_LIST_H__
#define __PEA_LIST_H__

#include <stddef.h>
#include <stdbool.h>

typedef struct PeaListNode {
    struct PeaListNode *pNext;
    struct PeaListNode *pPrev;
} PeaListNode_t;

static inline void peaNodeInit(PeaListNode_t *pNode)
{
    pNode->pNext = pNode;
    pNode->pPrev = pNode;
}

static inline bool peaListEmpty(PeaListNode_t *pHead)
{
    return pHead->pNext == pHead && pHead->pPrev == pHead;
}

static inline void peaListDel(PeaListNode_t *pNode)
{
    pNode->pPrev->pNext = pNode->pNext;
    pNode->pNext->pPrev = pNode->pPrev;
    return;
}

static inline void peaListAdd(PeaListNode_t *pNode, PeaListNode_t *pPrev, PeaListNode_t *pNext)
{
    pNode->pNext = pNext;
    pNode->pPrev = pPrev;
    pPrev->pNext = pNode;
    pNext->pPrev = pNode;
    return;
}

static inline void peaListAddTail(PeaListNode_t *pHead, PeaListNode_t *pNode)
{
    peaListAdd(pNode, pHead, pHead->pNext);
    return;
}

static inline PeaListNode_t *peaListHead(PeaListNode_t *pHead)
{
    if (peaListEmpty(pHead)) {
        return NULL;
    }
    return pHead->pPrev;
}

static inline PeaListNode_t *peaListPickHead(PeaListNode_t *pHead)
{
    PeaListNode_t *pNode = peaListHead(pHead);
    if (pNode == NULL) {
        return NULL;
    }
    peaListDel(pNode);
    return pNode;
}

static inline PeaListNode_t *peaListTail(PeaListNode_t *pHead)
{
    if (peaListEmpty(pHead)) {
        return NULL;
    }
    return pHead->pNext;
}

static inline PeaListNode_t *peaListPickTail(PeaListNode_t *pHead)
{
    PeaListNode_t *pNode = peaListTail(pHead);
    if (pNode == NULL) {
        return NULL;
    }
    peaListDel(pNode);
    return pNode;
}

#define PEA_LIST_ENTRY(ptr, type, member) ((type *)(((void *)ptr) - offsetof(type, member)))

#define PEA_LIST_FOREACH(pPos, pHead) for (PeaListNode_t pPos = pHead->pNext; pPos != pHead; pPos = pPos->pNext)

#endif