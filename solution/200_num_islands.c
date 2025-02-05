/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include "pea_queue.h"

static void visitMapDestroy(char **ppVisit, int size)
{
    if (ppVisit != NULL) {
        for (int i = 0; i < size; i++) {
            if (ppVisit[i] != NULL) {
                free(ppVisit[i]);
                ppVisit[i] = NULL;
            }
        }
        free(ppVisit);
    }
    return;
}

static char **visitMapCreate(int gridSize, int* gridColSize)
{
    char **ppVisit  = (char **)malloc(sizeof(*ppVisit) * gridSize);
    if (ppVisit == NULL) {
        goto l_fail;
    }
    (void)memset(ppVisit, 0, sizeof(*ppVisit) * gridSize);

    for (int  i = 0; i < gridSize; i++) {
        ppVisit[i] = (char *)malloc(sizeof(*(ppVisit[0])) *gridColSize[i]);
        if (ppVisit[i] == NULL) {
            goto l_fail;
        }
        (void)memset(ppVisit[i], 0, sizeof(*(ppVisit[0])) *gridColSize[i]);
    }
    goto l_end;

l_fail:
    visitMapDestroy(ppVisit, gridSize);
    ppVisit = NULL;
l_end:
    return ppVisit;
}

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

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int numIsLands = 0;
    Coord_t curCoord;
    Coord_t nextCoord;
    char **ppVisit = visitMapCreate(gridSize, gridColSize);
    if (ppVisit == NULL) {
        goto l_end;
    }
    PeaQueue_t *pNonIsLandQue = peaQueueCreate(gridSize * gridColSize[0], sizeof(curCoord));
    if (pNonIsLandQue == NULL) {
        goto l_end;
    }
    PeaQueue_t *pIsLandQue = peaQueueCreate(gridSize * gridColSize[0], sizeof(curCoord));
    if (pIsLandQue == NULL) {
        goto l_end;
    }

    curCoord.row = 0;
    curCoord.col = 0;

    ppVisit[curCoord.row][curCoord.col] = 1;
    if (grid[curCoord.row][curCoord.col] == '1') {
        pIsLandQue->pfPush(pIsLandQue, &curCoord);
    } else {
        pNonIsLandQue->pfPush(pNonIsLandQue, &curCoord);
    }

    while (pNonIsLandQue->pfEmpty(pNonIsLandQue) == false || pIsLandQue->pfEmpty(pIsLandQue) == false) {
        if (pIsLandQue->pfEmpty(pIsLandQue) == false) {
            numIsLands++;
        }
        while (pIsLandQue->pfEmpty(pIsLandQue) == false) {
            curCoord = *((Coord_t *)pIsLandQue->pfFront(pIsLandQue));
            pIsLandQue->pfPop(pIsLandQue);
            for (int i = 0; i < sizeof(nextCoordInc) / sizeof(nextCoordInc[0]); i++) {
                nextCoord.row = curCoord.row + nextCoordInc[i][0];
                nextCoord.col = curCoord.col + nextCoordInc[i][1];
                if (isCoordInside(nextCoord, gridSize, gridColSize[0]) == false 
                    || ppVisit[nextCoord.row][nextCoord.col] != 0) {
                    continue;
                }
                ppVisit[nextCoord.row][nextCoord.col] = 1;
                if (grid[nextCoord.row][nextCoord.col] == '1') {
                    pIsLandQue->pfPush(pIsLandQue, &nextCoord);
                } else {
                    pNonIsLandQue->pfPush(pNonIsLandQue, &nextCoord);
                }
            }
        }

        if (pNonIsLandQue->pfEmpty(pNonIsLandQue) == true) {
            continue;
        }
        curCoord = *((Coord_t *)pNonIsLandQue->pfFront(pNonIsLandQue));
        pNonIsLandQue->pfPop(pNonIsLandQue);
        for (int i = 0; i < sizeof(nextCoordInc) / sizeof(nextCoordInc[0]); i++) {
            nextCoord.row = curCoord.row + nextCoordInc[i][0];
            nextCoord.col = curCoord.col + nextCoordInc[i][1];
            if (isCoordInside(nextCoord, gridSize, gridColSize[0]) == false
                || ppVisit[nextCoord.row][nextCoord.col] != 0) {
                continue;
            }
            ppVisit[nextCoord.row][nextCoord.col] = 1;
            if (grid[nextCoord.row][nextCoord.col] == '1') {
                pIsLandQue->pfPush(pIsLandQue, &nextCoord);
                break;
            } else {
                pNonIsLandQue->pfPush(pNonIsLandQue, &nextCoord);
            }
        }
    }

l_end:
    visitMapDestroy(ppVisit, gridSize);
    if (pNonIsLandQue != NULL) {
        pNonIsLandQue->pfDestroy(pNonIsLandQue);
    }
    if (pIsLandQue != NULL) {
        pIsLandQue->pfDestroy(pIsLandQue);
    }
    return numIsLands;
}
// @lc code=end

