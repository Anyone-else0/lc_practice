#ifndef __208_ACHIEVE_TRIE_H__
#define __208_ACHIEVE_TRIE_H__

#define ELE_NUM_MAX (26)

typedef struct Trie_s {
    struct Trie_s *pNext[ELE_NUM_MAX];
    bool isWord;
    char val;
} Trie;

Trie* trieCreate(void);
void trieInsert(Trie* obj, char* word);
bool trieSearch(Trie* obj, char* word);
bool trieStartsWith(Trie* obj, char* prefix);
void trieFree(Trie* obj);

#endif