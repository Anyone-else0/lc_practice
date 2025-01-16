/*
 * @lc app=leetcode.cn id=417 lang=c
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pea_queue.h"

/*
typedef struct HeightInfo {
    int **ppHeights;
    int rowSize;
    int colSize;
    int **ppMark;
    int **ppRes;
    int resCap;
    int resNr;
    PeaQueue_t *pQue;
} HeightInfo_t;

typedef struct Coord {
    int row;
    int col;
} Coord_t;

static int nextCoordInc[][2] = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0},
};

static bool isCoordInside(Coord_t coord, int gridSize, int gridColSize)
{
    return coord.row >= 0 && coord.row < gridSize && coord.col >= 0 && coord.col < gridColSize;
}

static void reachPacific(HeightInfo_t *pInfo)
{
    PeaQueue_t *pQue = pInfo->pQue;
    Coord_t cur;
    Coord_t next;
    for (int i = 0; i < pInfo->colSize; i++) {
        cur.row = 0;
        cur.col = i;
        pQue->pfPush(pQue, &cur);
        pInfo->ppMark[cur.row][cur.col] = 1;
    }
    for (int i = 1; i < pInfo->rowSize; i++) {
        cur.row = i;
        cur.col = 0;
        pQue->pfPush(pQue, &cur);
        pInfo->ppMark[cur.row][cur.col] = 1;
    }

    while (pQue->pfEmpty(pQue) == false) {
        cur = *((Coord_t *)pQue->pfFront(pQue));
        pQue->pfPop(pQue);
        for (int i = 0; i < sizeof(nextCoordInc) / sizeof(nextCoordInc[0]); i++) {
            next.row = cur.row + nextCoordInc[i][0];
            next.col = cur.col + nextCoordInc[i][1];
            if (isCoordInside(next, pInfo->rowSize, pInfo->colSize) == false) {
                continue;
            }
            if (pInfo->ppMark[next.row][next.col] == 1) {
                continue;
            }
            if (pInfo->ppHeights[cur.row][cur.col] > pInfo->ppHeights[next.row][next.col]) {
                continue;
            }
            pInfo->ppMark[next.row][next.col] = 1;
            pQue->pfPush(pQue, &next);
        }
    }
}

static void reachAtlantic(HeightInfo_t *pInfo)
{
    PeaQueue_t *pQue = pInfo->pQue;
    Coord_t cur;
    Coord_t next;
    for (int i = 0; i < pInfo->colSize; i++) {
        cur.row = pInfo->rowSize - 1;
        cur.col = i;
        pQue->pfPush(pQue, &cur);
        if (pInfo->ppMark[cur.row][cur.col] == 1) {
            pInfo->ppRes[pInfo->resNr][0] = cur.row;
            pInfo->ppRes[pInfo->resNr][1] = cur.col;
            pInfo->resNr++;
        }
        pInfo->ppMark[cur.row][cur.col] = 2;
    }
    for (int i = 0; i < pInfo->rowSize - 1; i++) {
        cur.row = i;
        cur.col = pInfo->colSize - 1;
        pQue->pfPush(pQue, &cur);
        if (pInfo->ppMark[cur.row][cur.col] == 1) {
            pInfo->ppRes[pInfo->resNr][0] = cur.row;
            pInfo->ppRes[pInfo->resNr][1] = cur.col;
            pInfo->resNr++;
        }
        pInfo->ppMark[cur.row][cur.col] = 2;
    }

    while (pQue->pfEmpty(pQue) == false) {
        cur = *((Coord_t *)pQue->pfFront(pQue));
        pQue->pfPop(pQue);
        for (int i = 0; i < sizeof(nextCoordInc) / sizeof(nextCoordInc[0]); i++) {
            next.row = cur.row + nextCoordInc[i][0];
            next.col = cur.col + nextCoordInc[i][1];
            if (isCoordInside(next, pInfo->rowSize, pInfo->colSize) == false) {
                continue;
            }
            if (pInfo->ppMark[next.row][next.col] == 2) {
                continue;
            }
            if (pInfo->ppHeights[cur.row][cur.col] > pInfo->ppHeights[next.row][next.col]) {
                continue;
            }
            if (pInfo->ppMark[next.row][next.col] == 1) {
                pInfo->ppRes[pInfo->resNr][0] = next.row;
                pInfo->ppRes[pInfo->resNr][1] = next.col;
                pInfo->resNr++;
            }
            pInfo->ppMark[next.row][next.col] = 2;
            pQue->pfPush(pQue, &next);
        }
    }
}

int **pacificAtlantic(int **heights, int heightsSize, int *heightsColSize, int *returnSize, int **returnColumnSizes)
{
    HeightInfo_t info;
    info.ppHeights = heights;
    info.rowSize = heightsSize;
    info.colSize = heightsColSize[0];
    info.resCap = info.rowSize * info.colSize;
    info.ppRes = (int **)malloc(sizeof(*info.ppRes) * info.resCap);
    for (int i = 0; i < info.resCap; i++) {
        info.ppRes[i] = (int *)malloc(sizeof(info.ppRes[i][0]) * 2);
    }
    info.ppMark = (int **)malloc(sizeof(*info.ppMark) * info.rowSize);
    for (int i = 0; i < info.rowSize; i++) {
        info.ppMark[i] = (int *)malloc(sizeof(info.ppMark[i][0]) * info.colSize);
        (void)memset(info.ppMark[i], 0, sizeof(info.ppMark[i][0]) * info.colSize);
    }
    
    info.pQue = peaQueueCreate(info.rowSize * info.colSize, sizeof(Coord_t));
    info.resNr = 0;

    reachPacific(&info);
    reachAtlantic(&info);

    int **ppRes = info.ppRes;
    *returnSize = info.resNr;
    *returnColumnSizes = (int *)malloc(sizeof(**returnColumnSizes) * info.resNr);
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    info.pQue->pfDestroy(info.pQue);
    free(info.ppMark);
    return ppRes;
}
*/

typedef struct Info_s
{
    int **ppHeights;
    int rawSize;
    int colSize;

    int **ppMap;
    PeaQueue_t *pQue;
    bool isPacific;

    int **ppRes;
    int resNr;
} Info_t;

typedef struct Idx_s
{
    int rawIdx;
    int colIdx;
} Idx_t;

static int nextIdx[][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

static bool isValid(Info_t *pInfo, Idx_t *pIdx)
{
    return pIdx->rawIdx >= 0 && pIdx->rawIdx < pInfo->rawSize && pIdx->colIdx >= 0 && pIdx->colIdx < pInfo->colSize;
}

static void bfs(Info_t *pInfo)
{
    PeaQueue_t *pQue = pInfo->pQue;
    while (pQue->pfEmpty(pQue) == false) {
        Idx_t cur = *((Idx_t *)pQue->pfFront(pQue));
        pQue->pfPop(pQue);
        for (int i = 0; i < sizeof(nextIdx) / sizeof(nextIdx[0]); i++) {
            Idx_t nex;
            nex.rawIdx = cur.rawIdx + nextIdx[i][0];
            nex.colIdx = cur.colIdx + nextIdx[i][1];
            if (isValid(pInfo, &nex) == false) {
                continue;
            }
            if (pInfo->isPacific == false) {
                if (pInfo->ppMap[nex.rawIdx][nex.colIdx] != 2 && 
                    pInfo->ppHeights[nex.rawIdx][nex.colIdx] >= pInfo->ppHeights[cur.rawIdx][cur.colIdx]) {
                    if (pInfo->ppMap[nex.rawIdx][nex.colIdx] == 1) {
                        pInfo->ppRes[pInfo->resNr][0] = nex.rawIdx;
                        pInfo->ppRes[pInfo->resNr][1] = nex.colIdx;
                        pInfo->resNr++;
                    }
                    pInfo->ppMap[nex.rawIdx][nex.colIdx] = 2;
                    pQue->pfPush(pQue, &nex);
                } else {
                    continue;
                }
            } else {
                if (pInfo->ppMap[nex.rawIdx][nex.colIdx] == 0 && 
                    pInfo->ppHeights[nex.rawIdx][nex.colIdx] >= pInfo->ppHeights[cur.rawIdx][cur.colIdx]) {
                    pInfo->ppMap[nex.rawIdx][nex.colIdx] = 1;
                    pQue->pfPush(pQue, &nex);
                } else {
                    continue;
                }
            }
        }
    }
}

void reachPacific(Info_t *pInfo)
{
    pInfo->isPacific = true;
    for (int i = 0; i < pInfo->colSize; i++)
    {
        Idx_t idx = {.rawIdx = 0, .colIdx = i};
        pInfo->ppMap[idx.rawIdx][idx.colIdx] = 1;
        pInfo->pQue->pfPush(pInfo->pQue, &idx);
    }
    bfs(pInfo);
    for (int i = 0; i < pInfo->rawSize; i++)
    {
        Idx_t idx = {.rawIdx = i, .colIdx = 0};
        pInfo->ppMap[idx.rawIdx][idx.colIdx] = 1;
        pInfo->pQue->pfPush(pInfo->pQue, &idx);
    }
    bfs(pInfo);
    return;
}

void reachAtlantic(Info_t *pInfo)
{
    pInfo->isPacific = false;
    for (int i = 0; i < pInfo->colSize; i++)
    {
        Idx_t idx = {.rawIdx = pInfo->rawSize - 1, .colIdx = i};
        if (pInfo->ppMap[idx.rawIdx][idx.colIdx] == 1) {
            pInfo->ppRes[pInfo->resNr][0] = idx.rawIdx;
            pInfo->ppRes[pInfo->resNr][1] = idx.colIdx;
            pInfo->resNr++;
        }
        pInfo->ppMap[idx.rawIdx][idx.colIdx] = 2;
        pInfo->pQue->pfPush(pInfo->pQue, &idx);
    }
    bfs(pInfo);
    for (int i = 0; i < pInfo->rawSize; i++)
    {
        Idx_t idx = {.rawIdx = i, .colIdx = pInfo->colSize - 1};
        if (pInfo->ppMap[idx.rawIdx][idx.colIdx] == 1) {
            pInfo->ppRes[pInfo->resNr][0] = idx.rawIdx;
            pInfo->ppRes[pInfo->resNr][1] = idx.colIdx;
            pInfo->resNr++;
        }
        pInfo->ppMap[idx.rawIdx][idx.colIdx] = 2;
        pInfo->pQue->pfPush(pInfo->pQue, &idx);
    }
    bfs(pInfo);
    return;
}

int **pacificAtlantic(int **heights, int heightsSize, int *heightsColSize, int *returnSize, int **returnColumnSizes)
{
    Info_t info = {0};
    info.ppHeights = heights;
    info.rawSize = heightsSize;
    info.colSize = heightsColSize[0];
    info.ppMap = (int **)malloc(sizeof(int *) * info.rawSize);
    for (int i = 0; i < info.rawSize; i++) {
        info.ppMap[i] = (int *)malloc(sizeof(int) * info.colSize);
        memset(info.ppMap[i], 0, sizeof(int) * info.colSize);
    }
    info.pQue = peaQueueCreate(info.rawSize * info.colSize, sizeof(Idx_t));

    info.ppRes = (int **)malloc(sizeof(int *) * info.rawSize * info.colSize);
    for (int i = 0; i < info.rawSize * info.colSize; i++) {
        info.ppRes[i] = (int *)malloc(sizeof(int) * 2);
    }
    info.resNr = 0;

    reachPacific(&info);
    reachAtlantic(&info);

    for (int i = 0; i < info.rawSize; i++) {
        free(info.ppMap[i]);
    }
    free(info.ppMap);
    *returnSize = info.resNr;
    *returnColumnSizes = (int *)malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return info.ppRes;
}
// @lc code=end
