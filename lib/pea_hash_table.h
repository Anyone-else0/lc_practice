#ifndef __PEA_HASH_TABLE_H__
#define __PEA_HASH_TABLE_H__

typedef struct PeaHashPriv PeaHashPriv_t;

typedef struct PeaHashTable {
    void (*pfDestroy)(struct PeaHashTable *pTable);
    void *(*pfKvGet)(struct PeaHashTable *pTable, void *pKey);
    void *(*pfKvPick)(struct PeaHashTable *pTable, void *pKey);
    int (*pfKvPut)(struct PeaHashTable *pTable, void *pKv);
    struct PeaHashPriv *pPriv;
} PeaHashTable_t;

PeaHashTable_t *peaHashTableCreate(
    int bucketCap,
    int (*pfKeyCmp)(void *pKv1, void *pKv2),
    int (*pfGetIdx)(void *pKv),
    void *(pfGetKey)(void *pKv));

#endif