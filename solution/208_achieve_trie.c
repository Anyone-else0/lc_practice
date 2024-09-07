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
#include "pea_stack.h"
#include "pea_queue.h"

#define ELE_NUM_MAX (26)
typedef struct Trie_s {
    struct Trie_s *pNextNode[ELE_NUM_MAX];
    bool isWord;
    char val;
} Trie;

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
    pStack->pfPush(pStack, &pTmpNode);
    while (pStack->pfEmpty(pStack) == false) {
        pTmpNode = *((Trie **)pStack->pfTop(pStack));
        Trie *pNextNode = NULL;
        int i;
        for (i = 0; i < sizeof(pTmpNode->pNextNode) / sizeof(pTmpNode->pNextNode[0]); i++) {
            if (pTmpNode->pNextNode[i] != NULL) {
                pNextNode = pTmpNode->pNextNode[i];
                break;
            }
        }
        if (pNextNode == NULL) {
            pStack->pfPop(pStack);
            free(pTmpNode);
        } else {
            pTmpNode->pNextNode[i] = NULL;
            pStack->pfPush(pStack, &pNextNode);
        }
    }
    pStack->pfDestroy(pStack);
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

