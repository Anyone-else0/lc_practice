#include <stdio.h>
#include <string.h>
#include "pea_sort_ut.h"
#include "pea_sort.h"

static int peaUtNumSorCmp(void *pArray, int pos1, int pos2)
{
    return ((int *)pArray)[pos1] - ((int *)pArray)[pos2];
}

static int peaUtNumSorCmp1(void *pArray, int pos1, int pos2)
{
    return ((int *)pArray)[pos2] - ((int *)pArray)[pos1];
}

static void peaUtNumSortSwap(void *pArray, int pos1, int pos2)
{
    int tmp = ((int *)pArray)[pos1];
    ((int *)pArray)[pos1] = ((int *)pArray)[pos2];
    ((int *)pArray)[pos2] = tmp;
    return;
}

static void peaQSortTest(void)
{
    {
        int oriNums[] = {7, 5, 3, 9, 4, 8, 6};
        int numsSize = sizeof(oriNums) / sizeof(oriNums[0]);
        int nums[sizeof(oriNums) / sizeof(oriNums[0])];
        (void)memcpy(nums, oriNums, sizeof(nums));
        peaQSort(nums, 0, numsSize - 1, peaUtNumSorCmp, peaUtNumSortSwap);
        for (int i = 0; i < numsSize - 2; i++) {
            UT_ASSERT(nums[i] <= nums[i + 1]);
        }
        peaQSort(nums, 0, numsSize - 1, peaUtNumSorCmp1, peaUtNumSortSwap);
        for (int i = 0; i < numsSize - 2; i++) {
            UT_ASSERT(nums[i] >= nums[i + 1]);
        }
    }
    {
        int oriNums[] = {3, 3, 3, 9, 4, 8, 6};
        int numsSize = sizeof(oriNums) / sizeof(oriNums[0]);
        int nums[sizeof(oriNums) / sizeof(oriNums[0])];
        (void)memcpy(nums, oriNums, sizeof(nums));
        peaQSort(nums, 0, numsSize - 1, peaUtNumSorCmp, peaUtNumSortSwap);
        for (int i = 0; i < numsSize - 2; i++) {
            UT_ASSERT(nums[i] <= nums[i + 1]);
        }
        peaQSort(nums, 0, numsSize - 1, peaUtNumSorCmp1, peaUtNumSortSwap);
        for (int i = 0; i < numsSize - 2; i++) {
            UT_ASSERT(nums[i] >= nums[i + 1]);
        }
    }
}

static void peaHeapSortTest(void)
{
    {
        int oriNums[] = {7, 5, 3, 9, 4, 8, 6};
        int numsSize = sizeof(oriNums) / sizeof(oriNums[0]);
        int nums[sizeof(oriNums) / sizeof(oriNums[0])];
        (void)memcpy(nums, oriNums, sizeof(nums));
        peaHeapSort(nums, 0, numsSize - 1, peaUtNumSorCmp, peaUtNumSortSwap);
        for (int i = 0; i < numsSize - 2; i++) {
            UT_ASSERT(nums[i] <= nums[i + 1]);
        }
        peaHeapSort(nums, 0, numsSize - 1, peaUtNumSorCmp1, peaUtNumSortSwap);
        for (int i = 0; i < numsSize - 2; i++) {
            UT_ASSERT(nums[i] >= nums[i + 1]);
        }
    }
    {
        int oriNums[] = {3, 3, 3, 9, 4, 8, 6};
        int numsSize = sizeof(oriNums) / sizeof(oriNums[0]);
        int nums[sizeof(oriNums) / sizeof(oriNums[0])];
        (void)memcpy(nums, oriNums, sizeof(nums));
        peaHeapSort(nums, 0, numsSize - 1, peaUtNumSorCmp, peaUtNumSortSwap);
        for (int i = 0; i < numsSize - 2; i++) {
            UT_ASSERT(nums[i] <= nums[i + 1]);
        }
        peaHeapSort(nums, 0, numsSize - 1, peaUtNumSorCmp1, peaUtNumSortSwap);
        for (int i = 0; i < numsSize - 2; i++) {
            UT_ASSERT(nums[i] >= nums[i + 1]);
        }
    }
}

UtCase_t gPeaSortSuit[] = {
    {"peaQSortTest", peaQSortTest},
    {"peaHeapSortTest", peaHeapSortTest},
    {NULL, NULL}
};