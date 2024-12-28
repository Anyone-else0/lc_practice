#ifndef __211_WORD_DICTIONARY_H__
#define __211_WORD_DICTIONARY_H__

typedef struct {
    
} WordDictionary;

WordDictionary* wordDictionaryCreate();
void wordDictionaryAddWord(WordDictionary* obj, char* word);
bool wordDictionarySearch(WordDictionary* obj, char* word);
void wordDictionaryFree(WordDictionary* obj);

#endif