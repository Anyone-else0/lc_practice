/*
 * @lc app=leetcode.cn id=720 lang=c
 *
 * [720] 词典中最长的单词
 */

// @lc code=start

#define ELE_NUM_MAX (26)

typedef struct Trie_s
{
    struct Trie_s *pNext[ELE_NUM_MAX];
    bool isWord;
    char val;
} Trie_t;

static Trie_t *trieCreate(char** words, int wordsSize)
{
    Trie_t *pTrie = (Trie_t *)malloc(sizeof(Trie_t));
    memset(pTrie, 0, sizeof(*pTrie));

    for (int i = 0; i < wordsSize; i++) {
        char *pTmp = words[i];
        Trie_t *pNode = pTrie;
        while (*pTmp != '\0') {
            if (pNode->pNext[*pTmp - 'a'] == NULL) {
                pNode->pNext[*pTmp - 'a'] = (Trie_t *)malloc(sizeof(Trie_t));
                pNode = pNode->pNext[*pTmp - 'a'];
                memset(pNode, 0, sizeof(*pNode));
                pNode->val = *pTmp;
            } else {
                pNode = pNode->pNext[*pTmp - 'a'];
            }
            pTmp++;
        }
        pNode->isWord = true;
    }

    return pTrie;
}

void trieDestroy(Trie_t *pTrie)
{
    if (pTrie == NULL) {
        return;
    }
    for (int i = 0; i < sizeof(pTrie->pNext) / sizeof(pTrie->pNext[0]); i++) {
        if (pTrie->pNext[i] == NULL) {
            continue;
        }
        trieDestroy(pTrie->pNext[i]);
    }
    free(pTrie);
}

void dfs(Trie_t *pNode, char *pPath, int depth, char **longestWord)
{
    if (pNode == NULL) {
        return;
    }

    int curDepth = depth + 1;
    char *pCurPath = pPath + curDepth;

    for (int i = 0; i < sizeof(pNode->pNext) / sizeof(pNode->pNext[i]); i++) {
        Trie_t *pTmpNode = pNode->pNext[i];
        if (pTmpNode != NULL && pTmpNode->isWord == true) {
            *pCurPath = pTmpNode->val;
            *(pCurPath + 1) = '\0';
            if (curDepth + 1 > strlen(*longestWord)) {
                free(*longestWord);
                *longestWord = strdup(pPath);
            }
            dfs(pTmpNode, pPath, curDepth, longestWord);
        }
    }

    return;
}

char* longestWord(char** words, int wordsSize)
{
    Trie_t *pTrie = trieCreate(words, wordsSize);
    char *longest = strdup("");
    char path[1000] = {0};
    dfs(pTrie, path, -1, &longest);
    trieDestroy(pTrie);
    return longest;
}
// @lc code=end

