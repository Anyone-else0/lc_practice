/*
 * @lc app=leetcode.cn id=692 lang=c
 *
 * [692] 前K个高频单词
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_NUM (26)

typedef struct Trie_s
{
    struct Trie_s *pNext[MAX_WORD_NUM];
    char val;
    bool isWord;
    int Nr;
} Trie_t;

static Trie_t *trieCreate(char** words, int wordsSize)
{
    Trie_t *pTrie = (Trie_t *)malloc(sizeof(Trie_t));
    memset(pTrie, 0, sizeof(Trie_t));
    for (int i = 0; i < wordsSize; i++) {
        char *pTmp = words[i];
        Trie_t *pNode = pTrie;
        while (*pTmp != '\0') {
            if (pNode->pNext[*pTmp - 'a'] == NULL) {
                pNode->pNext[*pTmp - 'a'] = (Trie_t *)malloc(sizeof(Trie_t));
                memset(pNode->pNext[*pTmp - 'a'], 0, sizeof(Trie_t));
                pNode->pNext[*pTmp - 'a']->val = *pTmp;
            }
            pNode = pNode->pNext[*pTmp - 'a'];
            pTmp++;
        }
        pNode->isWord = true;
        pNode->Nr++;
    }
    return pTrie;
}

static void trieDestroy(Trie_t *pTrie)
{
    if (pTrie == NULL) {
        return;
    }
    for (int i = 0; i < MAX_WORD_NUM; i++) {
        trieDestroy(pTrie->pNext[i]);
    }
    free(pTrie);
    return;
}

static void findKth(char **pRes, int *pWordNr, int cap, int *nr, Trie_t *pTrie, char *buf, int bufLen)
{
    for (int i = 0; i < MAX_WORD_NUM; i++) {
        Trie_t *pNode = pTrie->pNext[i];
        if (pNode == NULL) {
            continue;
        }
        buf[bufLen] = pNode->val;
        if (pNode->isWord != false) {
            if (*nr < cap || pNode->Nr > pWordNr[*nr - 1]) {
                buf[bufLen + 1] = '\0';
                int insertIdx = 0;
                for (int j = *nr - 1; j >= 0; j--) {
                    if (pNode->Nr <= pWordNr[j]) {
                        insertIdx = j + 1;
                        break;
                    }
                }
                if (insertIdx <= *nr - 1) {
                    memmove(&pRes[insertIdx + 1], &pRes[insertIdx], sizeof(*pRes) * (cap - insertIdx - 1));
                    memmove(&pWordNr[insertIdx + 1], &pWordNr[insertIdx], sizeof(*pWordNr) * (cap - insertIdx - 1));
                }
                pRes[insertIdx] = strdup(buf);
                pWordNr[insertIdx] = pNode->Nr;

                if (*nr < cap) {
                    (*nr)++;
                }
            }
        }

        findKth(pRes, pWordNr, cap, nr, pNode, buf, bufLen + 1);
    }
    return;
}

char** topKFrequent(char** words, int wordsSize, int k, int* returnSize)
{
    Trie_t *pTrie = trieCreate(words, wordsSize);

    char **pRes = (char **)malloc(sizeof(char *) * k);
    *returnSize = k;
    int *pWordNr = (int *)malloc(sizeof(int) * k);
    memset(pWordNr, 0, sizeof(int) * k);
    int nr = 0;
    char buf[500 + 1];
    findKth(pRes, pWordNr, k, &nr, pTrie, buf, 0);
    free(pWordNr);

    trieDestroy(pTrie);
    return pRes;
}
// @lc code=end

