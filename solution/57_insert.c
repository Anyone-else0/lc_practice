/*
 * @lc app=leetcode.cn id=57 lang=c
 *
 * [57] 插入区间
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, 
    int* returnSize, int** returnColumnSizes)
{
    int **pRes = (int **)malloc(sizeof(int *) * (intervalsSize + 1));
    for (int i = 0; i < intervalsSize + 1; i++) {
        pRes[i] = (int *)malloc(sizeof(int) * 2);
        pRes[i][0] = 0;
        pRes[i][1] = 0;
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * (intervalsSize + 1));
    *returnSize = 0;

    int curInTerval[2];
    int intervalIdx = 0;
    int newIntervalIdx = 0;

    if (intervalsSize == 0) {
        pRes[0][0] = newInterval[0];
        pRes[0][1] = newInterval[1];
        *returnSize = 1;
        (*returnColumnSizes)[0] = 2;
        return pRes;
    }

    while (intervalIdx < intervalsSize || newIntervalIdx < 1) {
        if (newIntervalIdx < 1 && intervalIdx < intervalsSize) {
            if (intervals[intervalIdx][0] <= newInterval[1] && intervals[intervalIdx][1] >= newInterval[0]) {
                curInTerval[0] = intervals[intervalIdx][0] < newInterval[0] ? 
                    intervals[intervalIdx][0] : newInterval[0];
                while (intervalIdx <intervalsSize && intervals[intervalIdx][0] <= newInterval[1]) {
                    intervalIdx++;
                }
                curInTerval[1] = intervals[intervalIdx - 1][1] > newInterval[1] ? 
                intervals[intervalIdx - 1][1] : newInterval[1];
                newIntervalIdx++;
            } else {
                if (intervals[intervalIdx][0] > newInterval[1]) {
                    curInTerval[0] = newInterval[0];
                    curInTerval[1] = newInterval[1];
                    newIntervalIdx++;
                } else {
                    curInTerval[0] = intervals[intervalIdx][0];
                    curInTerval[1] = intervals[intervalIdx][1];
                    intervalIdx++;
                }
            }
        } else if (intervalIdx < intervalsSize) {
            curInTerval[0] = intervals[intervalIdx][0];
            curInTerval[1] = intervals[intervalIdx][1];
            intervalIdx++;
        } else {
            curInTerval[0] = newInterval[0];
            curInTerval[1] = newInterval[1];
            newIntervalIdx++;
        }
        pRes[*returnSize][0] = curInTerval[0];
        pRes[*returnSize][1] = curInTerval[1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    return pRes;
}
// @lc code=end

