#ifndef __PEA_HASH_TABLE_H__
#define __PEA_HASH_TABLE_H__

typedef struct PeaHashKv {
    void *pKey;
    int keyLen;
    void *pValue;
    int valueLen;
    char pad[0];
} PeaHashKv_t;

typedef struct HashListTable {
    int bucketCap;
    void **ppBucket;
} PeaHashTable_t;

PeaHashTable_t *peaHashTableCreate(int bucketCap);
void peaHashTableDestroy(PeaHashTable_t *pTable);
int peaHashTableKvGet(PeaHashTable_t *pTable, PeaHashKv_t *pKv);
int peaHashTableKvPick(PeaHashTable_t *pTable, PeaHashKv_t *pKv);
int peaHashTableKvPut(PeaHashTable_t *pTable, PeaHashKv_t *pKv);

#endif