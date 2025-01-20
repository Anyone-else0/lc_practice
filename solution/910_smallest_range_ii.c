/*
 * @lc app=leetcode.cn id=910 lang=c
 *
 * [910] 最小差值 II
 */

// @lc code=start
#include "pea_sort.h"

int peaSortCmpInt(void *pArray, int pos1, int pos2)
{
    int *pInt = (int *)pArray;
    return pInt[pos1] - pInt[pos2];
}

void peaSortSwapInt(void *pArray, int pos1, int pos2)
{
    int *pInt = (int *)pArray;
    int tmp = pInt[pos1];
    pInt[pos1] = pInt[pos2];
    pInt[pos2] = tmp;
}

int smallestRangeII(int* nums, int numsSize, int k)
{
    peaHeapSort(nums, 0, numsSize - 1, peaSortCmpInt, peaSortSwapInt);
    int res = nums[numsSize - 1] - nums[0];
    for (int i = 0; i < numsSize - 1; i++) {
        int max = nums[i] + k > nums[numsSize - 1] - k ? nums[i] + k : nums[numsSize - 1] - k;
        int min = nums[0] + k < nums[i + 1] - k ? nums[0] + k : nums[i + 1] - k;
        res = res < max - min ? res : max - min;
    }

    return res;
}
// @lc code=end

