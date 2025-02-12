/*
 * @lc app=leetcode.cn id=1817 lang=c
 *
 * [1817] 查找用户活跃分钟数
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "pea_hash_table.h"

typedef struct UsrHash
{
    int usrID;
    int timeNr;
    PeaHashTable_t *pTimeTable;
} UsrHash_t;

static int usrKeyCmp(void *pKey1, void *pKey2)
{
    return *((int*)pKey1) - *((int*)pKey2);
}
static int usrGetIdx(void *pKey)
{
    return *((int*)pKey);
}
static void *usrKeyGet(void *pKv)
{
    return &(((UsrHash_t *)pKv)->usrID);
}

typedef struct TimeHash
{
    int time;
} TimeHash_t;

static int timeKeyCmp(void *pKey1, void *pKey2)
{
    return *((int*)pKey1) - *((int*)pKey2);
}
static int timeGetIdx(void *pKey)
{
    return *((int*)pKey);
}
static void *timeKeyGet(void *pKv)
{
    return &(((TimeHash_t *)pKv)->time);
}

static void usrCleanTmieTable(void *pKv, void *pCtx)
{
    UsrHash_t *pUsrKv = (UsrHash_t *)pKv;
    pUsrKv->pTimeTable->pfDestroy(pUsrKv->pTimeTable);
    pUsrKv->pTimeTable = NULL;
}

int* findingUsersActiveMinutes(int** logs, int logsSize, int* logsColSize, int k, int* returnSize)
{
    int *pRes = (int *)malloc(sizeof(int) * k);
    memset(pRes, 0, sizeof(int) * k);

    PeaHashTable_t *pUsrHash = peaHashTableCreate(1000, usrKeyCmp, usrGetIdx, usrKeyGet);
    
    for (int i = 0; i < logsSize; i++) {
        UsrHash_t *pUsrKv = pUsrHash->pfKvGet(pUsrHash, &logs[i][0]);
        if (pUsrKv == NULL) {
            pUsrKv = (UsrHash_t *)malloc(sizeof(*pUsrKv));
            pUsrKv->usrID = logs[i][0];
            pUsrKv->timeNr = 0;
            pUsrKv->pTimeTable = peaHashTableCreate(1000, timeKeyCmp, timeGetIdx, timeKeyGet);
            pUsrHash->pfKvPut(pUsrHash, pUsrKv);
        }
        PeaHashTable_t *pTimeHash = pUsrKv->pTimeTable;
        TimeHash_t *pTimeKv = pTimeHash->pfKvGet(pTimeHash, &logs[i][1]);
        if (pTimeKv == NULL) {
            pTimeKv = (TimeHash_t *)malloc(sizeof(*pTimeKv));
            pTimeKv->time = logs[i][1];
            pTimeHash->pfKvPut(pTimeHash, pTimeKv);
            if (pUsrKv->timeNr != 0) {
                pRes[pUsrKv->timeNr - 1]--;
            }
            pUsrKv->timeNr++;
            pRes[pUsrKv->timeNr - 1]++;
        }
    }

    pUsrHash->pfTraverse(pUsrHash, usrCleanTmieTable, NULL);
    pUsrHash->pfDestroy(pUsrHash);

    *returnSize = k;
    return pRes;
}
// @lc code=end

