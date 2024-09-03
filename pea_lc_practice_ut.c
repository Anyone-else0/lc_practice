#include <string.h>
#include <stdlib.h>
#include "pea_lc_practice_ut.h"
#include "1_two_sum.h"
#include "215_find_kth_largest.h"
#include "208_achieve_trie.h"

static void twoSumTest(void)
{
    {
        int nums[] = {2, 7, 11, 15};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int target = 9;
        int returnSize;
        int *res = twoSum(nums, numsSize, target, &returnSize);
        UT_ASSERT(returnSize == 2);
        UT_ASSERT(res[0] == 0);
        UT_ASSERT(res[1] == 1);
        free(res);
    }
    {
        int nums[] = {1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int target = 11;
        int returnSize;
        int *res = twoSum(nums, numsSize, target, &returnSize);
        UT_ASSERT(returnSize == 2);
        UT_ASSERT(res[0] == 5);
        UT_ASSERT(res[1] == 11);
        free(res);

    }
    return;
}

static void findKthLargestTest(void)
{
    {
        int oriNums[] = {1};
        int nums[sizeof(oriNums) / sizeof(oriNums[0])];
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int k = 1;
        (void)memcpy(nums, oriNums, sizeof(nums));
        int res = findKthLargestStack(nums, numsSize, k);
        UT_ASSERT(res == 1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestInsert(nums, numsSize, k);
        UT_ASSERT(res == 1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestBubble(nums, numsSize, k);
        UT_ASSERT(res == 1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestQSort(nums, numsSize, k);
        UT_ASSERT(res == 1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargest(nums, numsSize, k);
        UT_ASSERT(res == 1);
    }
    {
        int oriNums[] = {2, 1};
        int nums[sizeof(oriNums) / sizeof(oriNums[0])];
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int k = 2;
        (void)memcpy(nums, oriNums, sizeof(nums));
        int res = findKthLargestStack(nums, numsSize, k);
        UT_ASSERT(res == 1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestInsert(nums, numsSize, k);
        UT_ASSERT(res == 1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestBubble(nums, numsSize, k);
        UT_ASSERT(res == 1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestQSort(nums, numsSize, k);
        UT_ASSERT(res == 1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargest(nums, numsSize, k);
        UT_ASSERT(res == 1);
    }
    {
        int oriNums[] = {3, 2, 1, 5, 6, 4};
        int nums[sizeof(oriNums) / sizeof(oriNums[0])];
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int k = 2;
        (void)memcpy(nums, oriNums, sizeof(nums));
        int res = findKthLargestStack(nums, numsSize, k);
        UT_ASSERT(res == 5);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestInsert(nums, numsSize, k);
        UT_ASSERT(res == 5);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestBubble(nums, numsSize, k);
        UT_ASSERT(res == 5);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestQSort(nums, numsSize, k);
        UT_ASSERT(res == 5);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargest(nums, numsSize, k);
        UT_ASSERT(res == 5);
    }
    {
        int oriNums[] = {-1, -1};
        int nums[sizeof(oriNums) / sizeof(oriNums[0])];
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int k = 2;
        (void)memcpy(nums, oriNums, sizeof(nums));
        int res = findKthLargestStack(nums, numsSize, k);
        UT_ASSERT(res == -1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestInsert(nums, numsSize, k);
        UT_ASSERT(res == -1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestBubble(nums, numsSize, k);
        UT_ASSERT(res == -1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargestQSort(nums, numsSize, k);
        UT_ASSERT(res == -1);
        (void)memcpy(nums, oriNums, sizeof(nums));
        res = findKthLargest(nums, numsSize, k);
        UT_ASSERT(res == -1);
    }
}

static void trieTest(void)
{
    bool rc;
    Trie *pTrie = trieCreate();
    trieInsert(pTrie, "apple");
    rc = trieSearch(pTrie, "apple");   // 返回 True
    UT_ASSERT(rc == true);
    rc = trieSearch(pTrie, "app");     // 返回 False
    UT_ASSERT(rc == false);
    rc = trieStartsWith(pTrie, "app"); // 返回 True
    UT_ASSERT(rc == true);
    trieInsert(pTrie, "app");
    rc = trieSearch(pTrie, "app");     // 返回 True
    UT_ASSERT(rc == true);
    trieFree(pTrie);
}

UtCase_t gPeaLcPracticeSuit[] = {
    {"twoSumTest", twoSumTest},
    {"findKthLargestTest", findKthLargestTest},
    {"trieTest", trieTest},
    {NULL, NULL},
};