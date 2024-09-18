/*
 * @lc app=leetcode.cn id=875 lang=c
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
#include <stdlib.h>
#include <stdbool.h>

int maxPilesNum(int* piles, int pilesSize)
{
    int maxNum = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > maxNum) {
            maxNum = piles[i];
        }
    }
    return maxNum;
}

bool canEatUp(int* piles, int pilesSize, int k, int h)
{
    bool rc = true;
    int curh = 0;
    if (k == 0) {
        rc = false;
        goto l_end;
    }
    for (int i = 0; i < pilesSize; i++) {
        curh += (piles[i] + (k - 1)) / k;
        if (curh > h) {
            rc = false;
            goto l_end;
        }
    }

l_end:
    return rc;
}

int minEatingSpeed(int* piles, int pilesSize, int h)
{
    int left = 0;
    int right = maxPilesNum(piles, pilesSize);
    while (left < right) {
        int mid = (left + right) / 2;
        if (canEatUp(piles, pilesSize, mid, h)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
// @lc code=end

