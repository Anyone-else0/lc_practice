#include <string.h>
#include <stdlib.h>
#include "pea_lc_practice_ut.h"
#include "1_two_sum.h"
#include "215_find_kth_largest.h"
#include "208_achieve_trie.h"
#include "503_next_greater_elements_ii.h"
#include "146_lru_cache.h"
#include "875_min_eating_speed.h"
#include "200_num_islands.h"
#include "417_pacific_atlantic.h"
#include "169_majority_element.h"

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

static void nextGreaterElementsIITest(void)
{
    {
        int nums[] = {1, 2, 1};
        int returnSize;
        int expect[] = {2, -1, 2};
        int *res = nextGreaterElements(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == expect[i]);
        }
        free(res);
    }
    {
        int nums[] = {1, 2, 3, 4, 3};
        int returnSize;
        int expect[] = {2, 3, 4, -1, 4};
        int *res = nextGreaterElements(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == expect[i]);
        }
        free(res);
    }
}

static void lruCacheTest(void)
{
    {
        LRUCache *pLru = lRUCacheCreate(2);
        lRUCachePut(pLru, 1, 1);
        lRUCachePut(pLru, 2, 2);
        int val = lRUCacheGet(pLru, 1);
        UT_ASSERT(val == 1);
        lRUCachePut(pLru, 3, 3);
        val = lRUCacheGet(pLru, 2);
        UT_ASSERT(val == -1);
        lRUCachePut(pLru, 4, 4);
        val = lRUCacheGet(pLru, 1);
        UT_ASSERT(val == -1);
        val = lRUCacheGet(pLru, 3);
        UT_ASSERT(val == 3);
        val = lRUCacheGet(pLru, 4);
        UT_ASSERT(val == 4);
        lRUCacheFree(pLru);
    }
    {
        LRUCache *pLru = lRUCacheCreate(2);
        lRUCachePut(pLru, 2, 1);
        lRUCachePut(pLru, 1, 1);
        lRUCachePut(pLru, 2, 3);
        lRUCachePut(pLru, 4, 1);
        int val = lRUCacheGet(pLru, 1);
        UT_ASSERT(val == -1);
        val = lRUCacheGet(pLru, 2);
        UT_ASSERT(val == 3);
        lRUCacheFree(pLru);
    }
}

static void minEatingSpeedTest(void)
{
    {
        int piles[] = {3, 6, 7, 11};
        int h = 8;
        int res = minEatingSpeed(piles, sizeof(piles) / sizeof(piles[0]), h);
        UT_ASSERT(res == 4);
    }
    {
        int piles[] = {30, 11, 23, 4, 20};
        int h = 5;
        int res = minEatingSpeed(piles, sizeof(piles) / sizeof(piles[0]), h);
        UT_ASSERT(res == 30);
    }
    {
        int piles[] = {30, 11, 23, 4, 20};
        int h = 6;
        int res = minEatingSpeed(piles, sizeof(piles) / sizeof(piles[0]), h);
        UT_ASSERT(res == 23);
    }
}

static void numIslandsTest(void)
{
    {
        char grid[][5] = {{'1', '1', '1', '1', '0'},
                        {'1', '1', '0', '1', '0'},
                        {'1', '1', '0', '0', '0'},
                        {'0', '0', '0', '0', '0'}};
        int gridSize = sizeof(grid) / sizeof(grid[0]);
        int gridColSize[sizeof(grid) / sizeof(grid[0])];
        char **ppGrid = (char **)malloc(sizeof(*ppGrid) * gridSize);
        for (int i = 0; i < gridSize; i++) {
            ppGrid[i] = grid[i];
            gridColSize[i] = sizeof(grid[i]) / sizeof(grid[i][0]);
        }

        int res = numIslands(ppGrid, gridSize, gridColSize);
        UT_ASSERT(res == 1);
        free(ppGrid);
    }
    {
        char grid[][5] = {{'1', '1', '0', '0', '0'},
                        {'1', '1', '0', '0', '0'},
                        {'0', '0', '1', '0', '0'},
                        {'0', '0', '0', '1', '1'}};
        int gridSize = sizeof(grid) / sizeof(grid[0]);
        int gridColSize[] = {sizeof(grid[0]) / sizeof(grid[0][0])};
        char **ppGrid = (char **)malloc(sizeof(*ppGrid) * gridSize);
        for (int i = 0; i < gridSize; i++) {
            ppGrid[i] = grid[i];
            gridColSize[i] = sizeof(grid[i]) / sizeof(grid[i][0]);
        }
        int res = numIslands(ppGrid, gridSize, gridColSize);
        UT_ASSERT(res == 3);
        free(ppGrid);
    }
    {
        char grid[][1] = {{'1'}};
        
        int gridSize = sizeof(grid) / sizeof(grid[0]);
        int gridColSize[] = {sizeof(grid[0]) / sizeof(grid[0][0])};
        char **ppGrid = (char **)malloc(sizeof(*ppGrid) * gridSize);
        for (int i = 0; i < gridSize; i++) {
            ppGrid[i] = grid[i];
            gridColSize[i] = sizeof(grid[i]) / sizeof(grid[i][0]);
        }
        int res = numIslands(ppGrid, gridSize, gridColSize);
        UT_ASSERT(res == 1);
        free(ppGrid);
    }
}

static void pacificAtlanticTest(void)
{
    {
        int heights[][5] = {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}};
        int heightsSize = sizeof(heights) / sizeof(heights[0]);
        int heightsColSize[sizeof(heights) / sizeof(heights[0])];
        int **ppHeights = (int **)malloc(sizeof(*ppHeights) * heightsSize);
        for (int i = 0; i < heightsSize; i++) {
            ppHeights[i] = heights[i];
            heightsColSize[i] = sizeof(heights[i]) / sizeof(heights[i][0]);
        }
        int expRes[][2] = {
            {0,4},
            {1,3},
            {1,4},
            {2,2},
            {3,0},
            {3,1},
            {4,0}};
        int returnSize;
        int *pReturnColumnSizes = NULL;

        int **ppRes = pacificAtlantic(ppHeights, heightsSize, heightsColSize, &returnSize, &pReturnColumnSizes);
        UT_ASSERT(returnSize == sizeof(expRes) / sizeof(expRes[0]));
        int i, j, k;
        for (i = 0; i < returnSize; i++) {
            UT_ASSERT(pReturnColumnSizes[i] == sizeof(expRes[0]) / sizeof(expRes[0][0]));
            for (j = 0; j < sizeof(expRes) / sizeof(expRes[0]); j++) {
                for (k = 0; k < pReturnColumnSizes[i]; k++) {
                    if (ppRes[i][k] != expRes[j][k]) {
                        break;
                    }
                }
                if (k >= pReturnColumnSizes[i]) {
                    break;
                }
            }
            UT_ASSERT(j < sizeof(expRes) / sizeof(expRes[0]));
        }
        for (i = 0; i < returnSize; i++) {
            free(ppRes[i]);
        }
        free(ppRes);
        free(ppHeights);
        free(pReturnColumnSizes);
    }
    {
        int heights[][2] = {
            {2, 1},
            {1, 2}};
        int heightsSize = sizeof(heights) / sizeof(heights[0]);
        int heightsColSize[sizeof(heights) / sizeof(heights[0])];
        int **ppHeights = (int **)malloc(sizeof(*ppHeights) * heightsSize);
        for (int i = 0; i < heightsSize; i++) {
            ppHeights[i] = heights[i];
            heightsColSize[i] = sizeof(heights[i]) / sizeof(heights[i][0]);
        }
        int expRes[][2] = {
            {0, 0},
            {0, 1},
            {1, 0},
            {1, 1}};
        int returnSize;
        int *pReturnColumnSizes = NULL;

        int **ppRes = pacificAtlantic(ppHeights, heightsSize, heightsColSize, &returnSize, &pReturnColumnSizes);
        UT_ASSERT(returnSize == sizeof(expRes) / sizeof(expRes[0]));
        int i, j, k;
        for (i = 0; i < returnSize; i++) {
            UT_ASSERT(pReturnColumnSizes[i] == sizeof(expRes[0]) / sizeof(expRes[0][0]));
            for (j = 0; j < sizeof(expRes) / sizeof(expRes[0]); j++) {
                for (k = 0; k < pReturnColumnSizes[i]; k++) {
                    if (ppRes[i][k] != expRes[j][k]) {
                        break;
                    }
                }
                if (k >= pReturnColumnSizes[i]) {
                    break;
                }
            }
            UT_ASSERT(j < sizeof(expRes) / sizeof(expRes[0]));
        }
        for (i = 0; i < returnSize; i++) {
            free(ppRes[i]);
        }
        free(ppRes);
        free(ppHeights);
        free(pReturnColumnSizes);
    }
}

static void majorityElementTest(void)
{
    {
        int nums[] = {2, 2, 1, 1, 1, 2, 2};
        int numsSize = sizeof(nums) / sizeof(nums[0]);

        int res = majorityElementHash(nums, numsSize);
        UT_ASSERT(res = 2);
    }
    {
        int nums[] = {2, 2, 1, 1, 1, 2, 2};
        int numsSize = sizeof(nums) / sizeof(nums[0]);

        int res = majorityElement(nums, numsSize);
        UT_ASSERT(res = 2);
    }
}

UtCase_t gPeaLcPracticeSuit[] = {
    {"twoSumTest", twoSumTest},
    {"findKthLargestTest", findKthLargestTest},
    {"trieTest", trieTest},
    {"nextGreaterElementsIITest", nextGreaterElementsIITest},
    {"lruCacheTest", lruCacheTest},
    {"minEatingSpeedTest", minEatingSpeedTest},
    {"numIslandsTest", numIslandsTest},
    {"pacificAtlanticTest", pacificAtlanticTest},
    {"majorityElementTest", majorityElementTest},
    {NULL, NULL},
};