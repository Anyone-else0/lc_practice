/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "stdlib.h"

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *pRes = (int *)malloc(sizeof(*pRes) * 2);
    *returnSize = 2;
    pRes[0] = -1;
    pRes[1] = -1;
    if (numsSize == 0) {
        goto l_end;
    }
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (nums[right] != target) {
        goto l_end;
    }
    pRes[0] = right;

    left = pRes[0];
    right = numsSize - 1;

    while (left < right) {
        int mid = ( left + right ) / 2 + 1;
        if (nums[mid] <= target) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    pRes[1] = left;

l_end:
    return pRes;
}
// @lc code=end

