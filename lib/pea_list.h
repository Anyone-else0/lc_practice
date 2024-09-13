#ifndef __PEA_LIST_H__
#define __PEA_LIST_H__

#include <stddef.h>
#include <stdbool.h>

typedef struct PeaListHead {
    struct PeaListHead *pNext;
    struct PeaListHead *pPrev;
} PeaListHead_t;

static inline void peaListNodeInit(PeaListHead_t *pNode)
{
    pNode->pNext = pNode;
    pNode->pPrev = pNode;
}

static inline bool peaListEmpty(PeaListHead_t *pHead)
{
    return pHead->pNext == pHead && pHead->pPrev == pHead;
}

static inline void peaListDel(PeaListHead_t *pNode)
{
    pNode->pPrev->pNext = pNode->pNext;
    pNode->pNext->pPrev = pNode->pPrev;
    return;
}

static inline void peaListAdd(PeaListHead_t *pNode, PeaListHead_t *pPrev, PeaListHead_t *pNext)
{
    pNode->pNext = pNext;
    pNode->pPrev = pPrev;
    pPrev->pNext = pNode;
    pNext->pPrev = pNode;
    return;
}

static inline void peaListAddTail(PeaListHead_t *pHead, PeaListHead_t *pNode)
{
    peaListAdd(pNode, pHead, pHead->pNext);
    return;
}

static inline void peaListAddHead(PeaListHead_t *pHead, PeaListHead_t *pNode)
{
    peaListAdd(pNode, pHead->pPrev, pHead);
    return;
}

static inline PeaListHead_t *peaListHead(PeaListHead_t *pHead)
{
    if (peaListEmpty(pHead)) {
        return NULL;
    }
    return pHead->pPrev;
}

static inline PeaListHead_t *peaListPickHead(PeaListHead_t *pHead)
{
    PeaListHead_t *pNode = peaListHead(pHead);
    if (pNode == NULL) {
        return NULL;
    }
    peaListDel(pNode);
    return pNode;
}

static inline PeaListHead_t *peaListTail(PeaListHead_t *pHead)
{
    if (peaListEmpty(pHead)) {
        return NULL;
    }
    return pHead->pNext;
}

static inline PeaListHead_t *peaListPickTail(PeaListHead_t *pHead)
{
    PeaListHead_t *pNode = peaListTail(pHead);
    if (pNode == NULL) {
        return NULL;
    }
    peaListDel(pNode);
    return pNode;
}

#define PEA_LIST_ENTRY(ptr, type, member) ((type *)(((void *)ptr) - offsetof(type, member)))

#define PEA_LIST_FOREACH(pPos, pHead) for (PeaListNode_t pPos = pHead->pNext; pPos != pHead; pPos = pPos->pNext)

#endif