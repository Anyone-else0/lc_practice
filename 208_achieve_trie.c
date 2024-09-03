/*
 * @lc app=leetcode.cn id=208 lang=c
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct PeaQueue {
    int cap;
    int eleSize;
    int rear;
    int front;
    void *pBuf;
    char buf[0];
} PeaQueue_t;

static PeaQueue_t *peaQueueCreate(int cap, int eleSize)
{
    PeaQueue_t *pQue = (PeaQueue_t *)malloc(sizeof(*pQue) + cap * eleSize);
    if (pQue == NULL) {
        printf("Que malloc failed\n");
        goto l_end;
    }
    pQue->cap = cap;
    pQue->eleSize = eleSize;
    pQue->front = -1;
    pQue->rear = -1;
    pQue->pBuf = pQue->buf;

l_end:
    return pQue;
}

static void peaQueueDestroy(PeaQueue_t *pQue)
{
    free(pQue);
}

static int peaQueuePop(PeaQueue_t *pQue)
{
    int rc = 0;
    if (pQue->front == -1) {
        rc = -1;
        goto l_end;
    } else if (pQue->front == pQue->rear) {
        pQue->front = -1;
        pQue->rear = -1;
    } else {
        pQue->front = (pQue->front == pQue->cap) ? 0 : pQue->front + 1;
    }

l_end:
    return rc;
}

static int peaQueuePush(PeaQueue_t *pQue, void *pEle)
{
    int rc = 0;
    if (pQue->rear == -1) {
        pQue->rear = 0;
        pQue->front = 0;
    } else {
        int nextRear = (pQue->rear == pQue->cap - 1) ? 0 : pQue->rear + 1;
        if (nextRear == pQue->front) {
            rc = -1;
            goto l_end;
        } else {
            pQue->rear = nextRear;
        }
    }
    (void)memcpy(pQue->pBuf + pQue->rear * pQue->eleSize, pEle, pQue->eleSize);

l_end:
    return rc;
}

static void *peaQueueFront(PeaQueue_t *pQue)
{
    void *pRes = NULL;
    if (pQue->front == -1) {
        goto l_end;
    } else {
        pRes = pQue->pBuf + pQue->front * pQue->eleSize;
    }

l_end:
    return pRes;
}

static bool peaQueueEmpty(PeaQueue_t *pQue)
{
    return pQue->front == -1;
}
*/

typedef struct PeaStack {
    int cap;
    int nr;
    int eleSize;
    void *pBuf;
} PeaStack_t;

static int peaStackPop(PeaStack_t *pStack)
{
    int rc = 0;
    if (pStack->nr == 0) {
        rc = -1;
        goto l_end;
    } else {
        pStack->nr--;
        goto l_end;
    }

l_end:
    return rc;
}

static int peaStackPush(PeaStack_t *pStack, void *pEle)
{
    int rc = 0;
    if (pStack->nr >= pStack->cap) {
        rc = -1;
        goto l_end;
    } else {
        (void)memcpy(pStack->pBuf + pStack->nr * pStack->eleSize, pEle, pStack->eleSize);
        pStack->nr++;
        goto l_end;
    }

l_end:
    return rc;
}

static void *peaStackTop(PeaStack_t *pStack)
{
    void *pRes = NULL;
    if (pStack->nr != 0) {
        pRes = pStack->pBuf + (pStack->nr - 1) * pStack->eleSize;
    }

    return pRes;
}

static bool peaStackEmpty(PeaStack_t *pStack)
{
    return pStack->nr == 0;
}

static PeaStack_t *peaStackCreate(int cap, int eleSize)
{
    PeaStack_t *pStack = (PeaStack_t *)malloc(sizeof(*pStack) + cap * eleSize);
    if (pStack == NULL) {
        goto l_end;
    }
    pStack->cap = cap;
    pStack->nr = 0;
    pStack->eleSize = eleSize;
    pStack->pBuf = ((void *)pStack) + sizeof(*pStack);

l_end:
    return pStack;
}

static void peaStackDestroy(PeaStack_t *pStack)
{
    free(pStack);
    return;
}

#ifndef __208_ACHIEVE_TRIE_H__

#define ELE_NUM_MAX (26)

typedef struct Trie_s {
    struct Trie_s *pNextNode[ELE_NUM_MAX];
    bool isWord;
    char val;
} Trie;

#endif

Trie* trieCreate(void)
{
    Trie *pTrie = (Trie *)malloc(sizeof(Trie));
    if (pTrie == NULL) {
        goto l_end;
    }
    (void)memset(pTrie, 0, sizeof(*pTrie));

l_end:
    return pTrie;
}

void trieInsert(Trie* obj, char* word)
{
    int len = strlen(word);
    Trie *pNode = obj;
    for (int curPos = 0; curPos < len; curPos++) {
        int charIdx = (int)(word[curPos] - 'a');
        if (pNode->pNextNode[charIdx] == NULL) {
            Trie *pTmpNode = (Trie *)malloc(sizeof(*pTmpNode));
            if (pTmpNode == NULL) {
                printf("Insert failed.\n");
            }
            (void)memset(pTmpNode, 0, sizeof(*pTmpNode));
            pTmpNode->val = word[curPos];
            pNode->pNextNode[charIdx] = pTmpNode;
        }
        pNode = pNode->pNextNode[charIdx];
    }
    pNode->isWord = true;
    return;
}

bool trieSearch(Trie* obj, char* word)
{
    int len = strlen(word);
    Trie *pNode = obj;
    bool rc = true;
    for (int curPos = 0; curPos < len; curPos++) {
        int charIdx = (int)(word[curPos] - 'a');
        if (pNode->pNextNode[charIdx] == NULL) {
            rc = false;
            goto l_end;
        }
        pNode = pNode->pNextNode[charIdx];
    }
    if (pNode->isWord == false) {
        rc = false;
        goto l_end;
    }

l_end:
    return rc;
}

bool trieStartsWith(Trie* obj, char* prefix)
{
    int len = strlen(prefix);
    Trie *pNode = obj;
    bool rc = true;
    for (int curPos = 0; curPos < len; curPos++) {
        int charIdx = (int)(prefix[curPos] - 'a');
        if (pNode->pNextNode[charIdx] == NULL) {
            rc = false;
            goto l_end;
        }
        pNode = pNode->pNextNode[charIdx];
    }

l_end:
    return rc;
}

/*
void trieFree(Trie* obj)
{
    PeaQueue_t *pQue = (PeaQueue_t *)peaQueueCreate(200000, sizeof(Trie *));
    Trie *pTmpNode = obj;
    peaQueuePush(pQue, &pTmpNode);
    while (peaQueueEmpty(pQue) == false) {
        Trie *pTmpNode = *((Trie **)peaQueueFront(pQue));
        peaQueuePop(pQue);
        for (int i = 0; i < sizeof(pTmpNode->pNextNode) / sizeof(pTmpNode->pNextNode[0]); i++) {
            if (pTmpNode->pNextNode[i] != NULL) {
                peaQueuePush(pQue, &(pTmpNode->pNextNode[i]));
            }
        }
        free(pTmpNode);
    }
    peaQueueDestroy(pQue);
    return;
}
*/

void trieFree(Trie* obj)
{
    PeaStack_t *pStack = peaStackCreate(2000, sizeof(Trie *));
    Trie *pTmpNode = obj;
    peaStackPush(pStack, &pTmpNode);
    while (peaStackEmpty(pStack) == false) {
        pTmpNode = *((Trie **)peaStackTop(pStack));
        Trie *pNextNode = NULL;
        int i;
        for (i = 0; i < sizeof(pTmpNode->pNextNode) / sizeof(pTmpNode->pNextNode[0]); i++) {
            if (pTmpNode->pNextNode[i] != NULL) {
                pNextNode = pTmpNode->pNextNode[i];
                break;
            }
        }
        if (pNextNode == NULL) {
            peaStackPop(pStack);
            free(pTmpNode);
        } else {
            pTmpNode->pNextNode[i] = NULL;
            peaStackPush(pStack, &pNextNode);
        }
    }
    peaStackDestroy(pStack);
    return;
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
// @lc code=end

