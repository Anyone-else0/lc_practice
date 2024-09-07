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
    void (*pfDestroy)(struct HashListTable *pTable);
    int (*pfKvGet)(struct HashListTable *pTable, PeaHashKv_t *pKv);
    int (*pfKvPick)(struct HashListTable *pTable, PeaHashKv_t *pKv);
    int (*pfKvPut)(struct HashListTable *pTable, PeaHashKv_t *pKv);
} PeaHashTable_t;

PeaHashTable_t *peaHashTableCreate(int bucketCap);

#endif