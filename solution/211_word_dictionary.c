/*
 * @lc app=leetcode.cn id=211 lang=c
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start

#define MAX_WORD_SIZE (26)

typedef struct WordDictionary_s {
    struct WordDictionary_s* next[MAX_WORD_SIZE];
    char val;
    bool isEnd;
} WordDictionary;

WordDictionary* wordDictionaryCreate()
{
    WordDictionary* obj = (WordDictionary*)malloc(sizeof(WordDictionary));
    if (obj == NULL) {
        return NULL;
    }
    (void)memset(obj, 0, sizeof(WordDictionary));
    return obj;
}

void wordDictionaryAddWord(WordDictionary* obj, char* word)
{
    char *pTmp = word;
    while (*pTmp != '\0') {
        if (obj->next[*pTmp - 'a'] == NULL) {
            WordDictionary* pNew = wordDictionaryCreate();
            if (pNew == NULL) {
                return;
            }
            pNew->val = *pTmp;
            obj->next[*pTmp - 'a'] = pNew;
        }
        obj = obj->next[*pTmp - 'a'];
        pTmp++;
    }
    obj->isEnd = true;
    return;
}

bool wordDictionarySearch(WordDictionary* obj, char* word)
{
    WordDictionary *pTmp = obj;
    char *pWord = word;
    bool ret = false;

    if (*word == '\0') {
        goto l_end;
    }

    for (int i = 0; i < sizeof(pTmp->next) / sizeof(pTmp->next[0]); i++) {
        if (pTmp->next[i] == NULL) {
            continue;
        }
        if (pTmp->next[i]->val == *pWord || *pWord == '.') {
            if (*(pWord + 1) == '\0' && pTmp->next[i]->isEnd == true) {
                ret = true;
                goto l_end;
            }
            ret = wordDictionarySearch(pTmp->next[i], pWord + 1);
            if (ret == true) {
                goto l_end;
            }
        }
    }

l_end:
    return ret;
}

void wordDictionaryFree(WordDictionary* obj)
{
    if (obj == NULL) {
        return;
    }
    for (int i = 0; i < MAX_WORD_SIZE; i++) {
        if (obj->next[i] != NULL) {
            wordDictionaryFree(obj->next[i]);
        }
    }
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/
// @lc code=end

