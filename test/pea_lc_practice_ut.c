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
#include "22_generate_parenthesis.h"
#include "698_can_partition_k_subsets.h"
#include "47_permute_unique.h"
#include "34_search_range.h"
#include "720_longest_word.h"
#include "155_min_stack.h"
#include "816_ambiguous_coordinates.h"
#include "211_word_dictionary.h"
#include "11_max_area.h"
#include "92_reverse_between_ii.h"
#include "817_num_components.h"
#include "214_shortest_palindrome.h"
#include "5_longest_palindrome.h"
#include "57_insert.h"
#include "23_merge_k_lists.h"
#include "692_top_k_frequent.h"
#include "142_detect_cycle_ii.h"
#include "144_preorder_traversal.h"
#include "145_postorder_traversal.h"
#include "94_inorder_traversal.h"
#include "287_find_duplicate.h"
#include "910_smallest_range_ii.h"
#include "460_lfu_cache.h"
#include "230_kth_smallest.h"
#include "98_is_valid_bst.h"

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
        UT_ASSERT(res == 2);
    }
    {
        int nums[] = {2, 2, 1, 1, 1, 2, 2};
        int numsSize = sizeof(nums) / sizeof(nums[0]);

        int res = majorityElement(nums, numsSize);
        UT_ASSERT(res == 2);
    }
}

static void generateParenthesisTest(void)
{
    int n = 3;
    int returnSize;
    char expRes[][6] = {"((()))", "(()())", "(())()", "()(())", "()()()"};

    char **ppRes = generateParenthesis(n, &returnSize);

    UT_ASSERT(returnSize == sizeof(expRes) / sizeof(expRes[0]));
    for (int i = 0; i < returnSize; i++) {
        int j;
        for (j = 0; j < returnSize; j++) {
            if (memcmp(ppRes[i], expRes[j], sizeof(expRes[j]))) {
                break;
            }
        }
        UT_ASSERT(j != returnSize);
    }

    for (int i = 0; i < returnSize; i++) {
        free(ppRes[i]);
    }
    free(ppRes);
}

static void canPartitionKSubsetsTest(void)
{
    {
        int nums[] = {4, 3, 2, 3, 5, 2, 1};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int k = 4;
        bool res = canPartitionKSubsets(nums, numsSize, k);
        UT_ASSERT(res == true);
    }
    {
        int nums[] = {1, 2, 3, 4};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int k = 3;
        bool res = canPartitionKSubsets(nums, numsSize, k);
        UT_ASSERT(res == false);
    }
    {
        int nums[] = {1, 1, 1, 1, 2, 2, 2, 2};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int k = 4;
        bool res = canPartitionKSubsets(nums, numsSize, k);
        UT_ASSERT(res == true);
    }
    {
        int nums[] = {2, 2, 2, 2, 3, 4, 5};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int k = 4;
        bool res = canPartitionKSubsets(nums, numsSize, k);
        UT_ASSERT(res == false);
    }
}

static void permuteUniqueTest(void)
{
    int nums[] = { 1, 1, 2 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int exp[][3] = {{ 1, 1, 2 }, { 1, 2, 1 }, { 2, 1, 1 }};
    int returnSize;
    int *returnColumeSize = NULL;
    int **res = permuteUnique(nums, numsSize, &returnSize, &returnColumeSize);
    UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
    for (int i = 0; i < returnSize; i++) {
        UT_ASSERT(returnColumeSize[i] == numsSize);
        int j = 0;
        for (j = 0; j < sizeof(exp) / sizeof(exp[0]); j++) {
            if (memcmp(res[i], exp[j], sizeof(exp[j])) == 0) {
                break;
            }
        }
        UT_ASSERT(j != sizeof(exp) / sizeof(exp[0]));
    }
    free(returnColumeSize);
    for (int i = 0; i < returnSize; i++) {
        free(res[i]);
    }
    free(res);
}

static void searchRangeTest(void)
{
    {
        int nums[] = { 5, 7, 7, 8, 8, 10 };
        int target = 8;
        int exp[] = { 3, 4 };
        int returnSize;
        int *pRes = searchRange(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(pRes[i] == exp[i]);
        }
        free(pRes);
    }
    {
        int nums[] = { 5, 7, 7, 8, 8, 10 };
        int target = 6;
        int exp[] = { -1, -1 };
        int returnSize;
        int *pRes = searchRange(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(pRes[i] == exp[i]);
        }
        free(pRes);
    }
    {
        int nums[1] = { 0 };
        int target = 0;
        int exp[] = { -1, -1 };
        int returnSize;
        int *pRes = searchRange(nums, 0, target, &returnSize);
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(pRes[i] == exp[i]);
        }
        free(pRes);
    }
}

static void longestWordTest(void)
{
    {
        char *words[] = {"w", "wo", "wor", "worl", "world"};
        char exp[] = "world";
        char *pRes = longestWord(words, sizeof(words) / sizeof(words[0]));
        UT_ASSERT(0 == memcmp(exp, pRes, sizeof(exp)));
        free(pRes);
    }
    {
        char *words[] = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
        char exp[] = "apple";
        char *pRes = longestWord(words, sizeof(words) / sizeof(words[0]));
        UT_ASSERT(0 == memcmp(exp, pRes, sizeof(exp)));
        free(pRes);
    }
}

static void minStackTest(void)
{
    MinStack *pMinStack = minStackCreate();
    minStackPush(pMinStack, -2);
    minStackPush(pMinStack, 0);
    minStackPush(pMinStack, -3);
    int min = minStackGetMin(pMinStack);
    UT_ASSERT(min == -3);
    minStackPop(pMinStack);
    int top = minStackTop(pMinStack);
    UT_ASSERT(top == 0);
    min = minStackGetMin(pMinStack);
    UT_ASSERT(min == -2);
    minStackFree(pMinStack);
}

static void ambiguousCoordinatesTest(void)
{
    {
        char *s = "(123)";
        char *exp[] = {"(1, 23)", "(1.2, 3)", "(12, 3)", "(1, 2.3)"};
        int returnSize;
        char **res = ambiguousCoordinates(s, &returnSize);
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            int j;
            for (j = 0; j < sizeof(exp) / sizeof(exp[0]); j++) {
                if (strcmp(res[i], exp[j]) == 0) {
                    break;
                }
            }
            UT_ASSERT(j != sizeof(exp) / sizeof(exp[0]));
        }
        for (int i = 0; i < returnSize; i++) {
            free(res[i]);
        }
        free(res);
    }
    {
        char *s = "(0123)";
        char *exp[] = {"(0, 123)", "(0, 1.23)", "(0, 12.3)", "(0.1, 23)", "(0.12, 3)", "(0.1, 2.3)"};
        int returnSize;
        char **res = ambiguousCoordinates(s, &returnSize);
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            int j;
            for (j = 0; j < sizeof(exp) / sizeof(exp[0]); j++) {
                if (strcmp(res[i], exp[j]) == 0) {
                    break;
                }
            }
            UT_ASSERT(j != sizeof(exp) / sizeof(exp[0]));
        }
        for (int i = 0; i < returnSize; i++) {
            free(res[i]);
        }
        free(res);
    }
    {
        char *s = "(00011)";
        char *exp[] = {"(0, 0.011)", "(0.001, 1)"};
        int returnSize;
        char **res = ambiguousCoordinates(s, &returnSize);
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            int j;
            for (j = 0; j < sizeof(exp) / sizeof(exp[0]); j++) {
                if (strcmp(res[i], exp[j]) == 0) {
                    break;
                }
            }
            UT_ASSERT(j != sizeof(exp) / sizeof(exp[0]));
        }
        for (int i = 0; i < returnSize; i++) {
            free(res[i]);
        }
        free(res);
    }
}

static void wordDictionaryTest(void)
{
    WordDictionary* obj = wordDictionaryCreate();
    wordDictionaryAddWord(obj, "bad");
    wordDictionaryAddWord(obj, "dad");
    wordDictionaryAddWord(obj, "mad");
    UT_ASSERT(wordDictionarySearch(obj, "pad") == false); // returns false
    UT_ASSERT(wordDictionarySearch(obj, "bad") == true);  // returns true
    UT_ASSERT(wordDictionarySearch(obj, ".ad") == true);  // returns true
    UT_ASSERT(wordDictionarySearch(obj, "b..") == true);  // returns true
    wordDictionaryFree(obj);
}

static void maxAreaTest(void)
{
    {
        int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int heightSize = sizeof(height) / sizeof(height[0]);
        int res = maxArea(height, heightSize);
        UT_ASSERT(res == 49);
    }
    {
        int height[] = {1, 1};
        int heightSize = sizeof(height) / sizeof(height[0]);
        int res = maxArea(height, heightSize);
        UT_ASSERT(res == 1);
    }
    {
        int height[] = {4, 3, 2, 1, 4};
        int heightSize = sizeof(height) / sizeof(height[0]);
        int res = maxArea(height, heightSize);
        UT_ASSERT(res == 16);
    }
    {
        int height[] = {1, 2, 1};
        int heightSize = sizeof(height) / sizeof(height[0]);
        int res = maxArea(height, heightSize);
        UT_ASSERT(res == 2);
    }
}

static struct ListNode* singleListCreateFromNums(int* nums, int numsSize) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = nums[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

static void singleListFree(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

static void reverseBetweenIITest(void)
{
    {
        int nums[] = {1, 2, 3, 4, 5};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int left = 2;
        int right = 4;
        int exp[] = {1, 4, 3, 2, 5};
        struct ListNode *pHead = singleListCreateFromNums(nums, numsSize);
        struct ListNode *pRes = reverseBetween(pHead, left, right);
        int i = 0;
        while (pRes) {
            UT_ASSERT(pRes->val == exp[i]);
            pRes = pRes->next;
            i++;
        }
        UT_ASSERT(i == numsSize);
        singleListFree(pRes);
    }
    {
        int nums[] = {5};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int left = 1;
        int right = 1;
        int exp[] = {5};
        struct ListNode *pHead = singleListCreateFromNums(nums, numsSize);
        struct ListNode *pRes = reverseBetween(pHead, left, right);
        int i = 0;
        while (pRes) {
            UT_ASSERT(pRes->val == exp[i]);
            pRes = pRes->next;
            i++;
        }
        UT_ASSERT(i == numsSize);
        singleListFree(pRes);
    }
    {
        int nums[] = {3, 5};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int left = 1;
        int right = 2;
        int exp[] = {5, 3};
        struct ListNode *pHead = singleListCreateFromNums(nums, numsSize);
        struct ListNode *pRes = reverseBetween(pHead, left, right);
        int i = 0;
        while (pRes) {
            UT_ASSERT(pRes->val == exp[i]);
            pRes = pRes->next;
            i++;
        }
        UT_ASSERT(i == numsSize);
        singleListFree(pRes);
    }
}

static void numComponentsTest(void)
{
    {
        int nums[] = {0, 1, 2, 3};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int G[] = {0, 1, 3};
        int GSize = sizeof(G) / sizeof(G[0]);
        struct ListNode *pHead = singleListCreateFromNums(nums, numsSize);
        int res = numComponents(pHead, G, GSize);
        UT_ASSERT(res == 2);
        singleListFree(pHead);
    }
    {
        int nums[] = {0, 1, 2, 3, 4};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int G[] = {0, 3, 1, 4};
        int GSize = sizeof(G) / sizeof(G[0]);
        struct ListNode *pHead = singleListCreateFromNums(nums, numsSize);
        int res = numComponents(pHead, G, GSize);
        UT_ASSERT(res == 2);
        singleListFree(pHead);
    }
}

static void shortestPalindromeTest(void)
{
    {
        char s[] = "aacecaaa";
        char exp[] = "aaacecaaa";
        char *res = shortestPalindrome(s);
        UT_ASSERT(strcmp(res, exp) == 0);
        free(res);
    }
    {
        char s[] = "abcd";
        char exp[] = "dcbabcd";
        char *res = shortestPalindrome(s);
        UT_ASSERT(strcmp(res, exp) == 0);
        free(res);
    }
    {
        char s[] = "a";
        char exp[] = "a";
        char *res = shortestPalindrome(s);
        UT_ASSERT(strcmp(res, exp) == 0);
        free(res);
    }
}

static void longestPalindromeTest(void)
{
    {
        char s[] = "babad";
        char exp[] = "bab";
        char *res = longestPalindrome(s);
        UT_ASSERT(strcmp(res, exp) == 0);
        free(res);
    }
    {
        char s[] = "cbbd";
        char exp[] = "bb";
        char *res = longestPalindrome(s);
        UT_ASSERT(strcmp(res, exp) == 0);
        free(res);
    }
}

static void insertTest(void)
{
    {
        int intervalsArr[][2] = {{1, 3}, {6, 9}};
        int intervalsSize = sizeof(intervalsArr) / sizeof(intervalsArr[0]);
        int intervalsColSize[] = {2, 2};
        int newInterval[] = {2, 5};
        int exp[][2] = {{1, 5}, {6, 9}};
        int returnSize;
        int *returnColumnSizes = NULL;
        int **intervals = (int **)malloc(intervalsSize * sizeof(int *));
        for (int i = 0; i < intervalsSize; i++) {
            intervals[i] = intervalsArr[i];
        }
        int **res = insert(intervals, intervalsSize, intervalsColSize, newInterval, sizeof(newInterval) / sizeof(newInterval[0]), &returnSize, &returnColumnSizes);
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(returnColumnSizes[i] == 2);
            for (int j = 0; j < 2; j++) {
                UT_ASSERT(res[i][j] == exp[i][j]);
            }
        }
        for (int i = 0; i < returnSize; i++) {
            free(res[i]);
        }
        free(res);
        free(returnColumnSizes);
        free(intervals);
    }
    {
        int intervalsArr[][2] = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
        int intervalsSize = sizeof(intervalsArr) / sizeof(intervalsArr[0]);
        int intervalsColSize[] = {2, 2, 2, 2, 2};
        int newInterval[] = {4, 8};
        int exp[][2] = {{1, 2}, {3, 10}, {12, 16}};
        int returnSize;
        int *returnColumnSizes = NULL;
        int **intervals = (int **)malloc(intervalsSize * sizeof(int *));
        for (int i = 0; i < intervalsSize; i++) {
            intervals[i] = intervalsArr[i];
        }
        int **res = insert(intervals, intervalsSize, intervalsColSize, newInterval, sizeof(newInterval) / sizeof(newInterval[0]), &returnSize, &returnColumnSizes);
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(returnColumnSizes[i] == 2);
            for (int j = 0; j < 2; j++) {
                UT_ASSERT(res[i][j] == exp[i][j]);
            }
        }
        for (int i = 0; i < returnSize; i++) {
            free(res[i]);
        }
        free(res);
        free(returnColumnSizes);
        free(intervals);
    }
    {
        int intervalsArr[][2] = {{1, 5}};
        int intervalsSize = sizeof(intervalsArr) / sizeof(intervalsArr[0]);
        int intervalsColSize[] = {2};
        int newInterval[] = {6, 8};
        int exp[][2] = {{1, 5}, {6, 8}};
        int returnSize;
        int *returnColumnSizes = NULL;
        int **intervals = (int **)malloc(intervalsSize * sizeof(int *));
        for (int i = 0; i < intervalsSize; i++) {
            intervals[i] = intervalsArr[i];
        }
        int **res = insert(intervals, intervalsSize, intervalsColSize, newInterval, sizeof(newInterval) / sizeof(newInterval[0]), &returnSize, &returnColumnSizes);
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(returnColumnSizes[i] == 2);
            for (int j = 0; j < 2; j++) {
                UT_ASSERT(res[i][j] == exp[i][j]);
            }
        }
        for (int i = 0; i < returnSize; i++) {
            free(res[i]);
        }
        free(res);
        free(returnColumnSizes);
        free(intervals);
    }
}

static void mergeKListsTest(void)
{
    {
        int nums1[] = {1, 4, 5};
        int nums2[] = {1, 3, 4};
        int nums3[] = {2, 6};
        struct ListNode *pList1 = singleListCreateFromNums(nums1, sizeof(nums1) / sizeof(nums1[0]));
        struct ListNode *pList2 = singleListCreateFromNums(nums2, sizeof(nums2) / sizeof(nums2[0]));
        struct ListNode *pList3 = singleListCreateFromNums(nums3, sizeof(nums3) / sizeof(nums3[0]));
        struct ListNode *lists[] = {pList1, pList2, pList3};
        struct ListNode *pRes = mergeKLists(lists, sizeof(lists) / sizeof(lists[0]));
        int exp[] = {1, 1, 2, 3, 4, 4, 5, 6};
        int i = 0;
        while (pRes) {
            UT_ASSERT(pRes->val == exp[i]);
            pRes = pRes->next;
            i++;
        }
        UT_ASSERT(i == sizeof(exp) / sizeof(exp[0]));
        singleListFree(pRes);
    }
    {
        struct ListNode *lists[] = {NULL};
        struct ListNode *pRes = mergeKLists(lists, sizeof(lists) / sizeof(lists[0]));
        UT_ASSERT(pRes == NULL);
    }
    {
        struct ListNode *lists[] = {NULL, NULL};
        struct ListNode *pRes = mergeKLists(lists, sizeof(lists) / sizeof(lists[0]));
        UT_ASSERT(pRes == NULL);
    }
    {
        int nums1[] = {};
        int nums2[] = {1};
        struct ListNode *pList1 = singleListCreateFromNums(nums1, sizeof(nums1) / sizeof(nums1[0]));
        struct ListNode *pList2 = singleListCreateFromNums(nums2, sizeof(nums2) / sizeof(nums2[0]));
        struct ListNode *lists[] = {pList1, pList2};
        struct ListNode *pRes = mergeKLists(lists, sizeof(lists) / sizeof(lists[0]));
        int exp[] = {1};
        int i = 0;
        while (pRes) {
            UT_ASSERT(pRes->val == exp[i]);
            pRes = pRes->next;
            i++;
        }
        UT_ASSERT(i == sizeof(exp) / sizeof(exp[0]));
        singleListFree(pRes);
    }
}

static void topKFrequentTest(void)
{
    {
        char *words[] = {"i", "love", "leetcode", "i", "love", "coding"};
        int wordsSize = sizeof(words) / sizeof(words[0]);
        int k = 3;
        char *exp[] = {"i", "love", "coding"};
        int returnSize;
        char **pRes = topKFrequent(words, wordsSize, k, &returnSize);
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(strcmp(pRes[i], exp[i]) == 0);
        }
        for (int i = 0; i < returnSize; i++) {
            free(pRes[i]);
        }
        free(pRes);
    }
}

static void detectCycleIITest(void)
{
    {
        int nums[] = {3, 2, 0, -4};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        struct ListNode *pHead = singleListCreateFromNums(nums, numsSize);
        struct ListNode *pTail = pHead;
        while (pTail->next) {
            pTail = pTail->next;
        }
        struct ListNode *pCycle = pHead->next;
        pTail->next = pCycle;
        struct ListNode *pRes = detectCycle(pHead);
        UT_ASSERT(pRes == pCycle);
        pTail->next = NULL;
        singleListFree(pHead);
    }
    {
        int nums[] = {1, 2};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        struct ListNode *pHead = singleListCreateFromNums(nums, numsSize);
        struct ListNode *pTail = pHead;
        while (pTail->next) {
            pTail = pTail->next;
        }
        struct ListNode *pCycle = pHead;
        pTail->next = pCycle;
        struct ListNode *pRes = detectCycle(pHead);
        UT_ASSERT(pRes == pCycle);
        pTail->next = NULL;
        singleListFree(pHead);
    }
    {
        int nums[] = {1};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        struct ListNode *pHead = singleListCreateFromNums(nums, numsSize);
        struct ListNode *pCycle = NULL;
        struct ListNode *pRes = detectCycle(pHead);
        UT_ASSERT(pRes == pCycle);
        singleListFree(pHead);
    }
}

static void preorderTraversalTest(void)
{
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 1;
        root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->val = 2;
        root->left->left = NULL;
        root->left->right = NULL;
        root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->val = 3;
        root->right->left = NULL;
        root->right->right = NULL;

        int returnSize;
        int *res = preorderTraversal(root, &returnSize);
        int exp[] = {1, 2, 3};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == exp[i]);
        }
        free(res);
        free(root->left);
        free(root->right);
        free(root);
    }
    {
        struct TreeNode *root = NULL;
        int returnSize;
        int *res = preorderTraversal(root, &returnSize);
        UT_ASSERT(returnSize == 0);
        UT_ASSERT(res != NULL);
        free(res);
    }
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 1;
        root->left = NULL;
        root->right = NULL;

        int returnSize;
        int *res = preorderTraversal(root, &returnSize);
        int exp[] = {1};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == exp[i]);
        }
        free(res);
        free(root);
    }
}

static void postorderTraversalTest(void)
{
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 1;
        root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->val = 2;
        root->left->left = NULL;
        root->left->right = NULL;
        root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->val = 3;
        root->right->left = NULL;
        root->right->right = NULL;

        int returnSize;
        int *res = postorderTraversal(root, &returnSize);
        int exp[] = {2, 3, 1};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == exp[i]);
        }
        free(res);
        free(root->left);
        free(root->right);
        free(root);
    }
    {
        struct TreeNode *root = NULL;
        int returnSize;
        int *res = postorderTraversal(root, &returnSize);
        UT_ASSERT(returnSize == 0);
        UT_ASSERT(res != NULL);
        free(res);
    }
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 1;
        root->left = NULL;
        root->right = NULL;

        int returnSize;
        int *res = postorderTraversal(root, &returnSize);
        int exp[] = {1};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == exp[i]);
        }
        free(res);
        free(root);
    }
}

static void inorderTraversalTest(void)
{
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 1;
        root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->val = 2;
        root->left->left = NULL;
        root->left->right = NULL;
        root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->val = 3;
        root->right->left = NULL;
        root->right->right = NULL;

        int returnSize;
        int *res = inorderTraversal(root, &returnSize);
        int exp[] = {2, 1, 3};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == exp[i]);
        }
        free(res);
        free(root->left);
        free(root->right);
        free(root);
    }
    {
        struct TreeNode *root = NULL;
        int returnSize;
        int *res = inorderTraversal(root, &returnSize);
        UT_ASSERT(returnSize == 0);
        UT_ASSERT(res != NULL);
        free(res);
    }
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 1;
        root->left = NULL;
        root->right = NULL;

        int returnSize;
        int *res = inorderTraversal(root, &returnSize);
        int exp[] = {1};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == exp[i]);
        }
        free(res);
        free(root);
    }
}

static void findDuplicateTest(void)
{
    {
        int nums[] = {1, 3, 4, 2, 2};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int res = findDuplicate(nums, numsSize);
        UT_ASSERT(res == 2);
    }
    {
        int nums[] = {3, 1, 3, 4, 2};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int res = findDuplicate(nums, numsSize);
        UT_ASSERT(res == 3);
    }
    {
        int nums[] = {1, 1};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int res = findDuplicate(nums, numsSize);
        UT_ASSERT(res == 1);
    }
    {
        int nums[] = {1, 1, 2};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int res = findDuplicate(nums, numsSize);
        UT_ASSERT(res == 1);
    }
}

static void smallestRangeIITest(void)
{
    {
        int A[] = {1};
        int ASize = sizeof(A) / sizeof(A[0]);
        int K = 0;
        int res = smallestRangeII(A, ASize, K);
        UT_ASSERT(res == 0);
    }
    {
        int A[] = {0, 10};
        int ASize = sizeof(A) / sizeof(A[0]);
        int K = 2;
        int res = smallestRangeII(A, ASize, K);
        UT_ASSERT(res == 6);
    }
    {
        int A[] = {1, 3, 6};
        int ASize = sizeof(A) / sizeof(A[0]);
        int K = 3;
        int res = smallestRangeII(A, ASize, K);
        UT_ASSERT(res == 3);
    }
}

static void lfuCacheTest(void)
{
    LFUCache *pLFUCache = lFUCacheCreate(2);
    lFUCachePut(pLFUCache, 1, 1);
    lFUCachePut(pLFUCache, 2, 2);
    UT_ASSERT(lFUCacheGet(pLFUCache, 1) == 1);
    lFUCachePut(pLFUCache, 3, 3);
    UT_ASSERT(lFUCacheGet(pLFUCache, 2) == -1);
    UT_ASSERT(lFUCacheGet(pLFUCache, 3) == 3);
    lFUCachePut(pLFUCache, 4, 4);
    UT_ASSERT(lFUCacheGet(pLFUCache, 1) == -1);
    UT_ASSERT(lFUCacheGet(pLFUCache, 3) == 3);
    UT_ASSERT(lFUCacheGet(pLFUCache, 4) == 4);
    lFUCacheFree(pLFUCache);
}

static void kthSmallestTest(void)
{
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 3;
        root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->val = 1;
        root->left->left = NULL;
        root->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->right->val = 2;
        root->left->right->left = NULL;
        root->left->right->right = NULL;
        root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->val = 4;
        root->right->left = NULL;
        root->right->right = NULL;

        int k = 1;
        int res = kthSmallest(root, k);
        UT_ASSERT(res == 1);

        free(root->left->right);
        free(root->left);
        free(root->right);
        free(root);
    }
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 5;
        root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->val = 3;
        root->left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->left->val = 2;
        root->left->left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->left->left->val = 1;
        root->left->left->left->left = NULL;
        root->left->left->left->right = NULL;
        root->left->left->right = NULL;
        root->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->right->val = 4;
        root->left->right->left = NULL;
        root->left->right->right = NULL;
        root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->val = 6;
        root->right->left = NULL;
        root->right->right = NULL;

        int k = 3;
        int res = kthSmallest(root, k);
        UT_ASSERT(res == 3);

        free(root->left->left->left);
        free(root->left->left);
        free(root->left->right);
        free(root->left);
        free(root->right);
        free(root);
    }
}

static void isValidBSTTest(void)
{
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 2;
        root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->val = 1;
        root->left->left = NULL;
        root->left->right = NULL;
        root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->val = 3;
        root->right->left = NULL;
        root->right->right = NULL;

        UT_ASSERT(isValidBST(root) == true);

        free(root->left);
        free(root->right);
        free(root);
    }
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 5;
        root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->val = 1;
        root->left->left = NULL;
        root->left->right = NULL;
        root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->val = 4;
        root->right->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->left->val = 3;
        root->right->left->left = NULL;
        root->right->left->right = NULL;
        root->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->right->val = 6;
        root->right->right->left = NULL;
        root->right->right->right = NULL;

        UT_ASSERT(isValidBST(root) == false);

        free(root->left);
        free(root->right->left);
        free(root->right->right);
        free(root->right);
        free(root);
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
    {"generateParenthesisTest", generateParenthesisTest},
    {"canPartitionKSubsetsTest", canPartitionKSubsetsTest},
    {"permuteUniqueTest", permuteUniqueTest},
    {"searchRangeTest", searchRangeTest},
    {"longestWordTest", longestWordTest},
    {"minStackTest", minStackTest},
    {"ambiguousCoordinatesTest", ambiguousCoordinatesTest},
    {"wordDictionaryTest", wordDictionaryTest},
    {"maxAreaTest", maxAreaTest},
    {"reverseBetweenIITest", reverseBetweenIITest},
    {"numComponentsTest", numComponentsTest},
    {"shortestPalindromeTest", shortestPalindromeTest},
    {"longestPalindromeTest", longestPalindromeTest},
    {"insertTest", insertTest},
    {"mergeKListsTest", mergeKListsTest},
    {"topKFrequentTest", topKFrequentTest},
    {"detectCycleIITest", detectCycleIITest},
    {"preorderTraversalTest", preorderTraversalTest},
    {"postorderTraversalTest", postorderTraversalTest},
    {"inorderTraversalTest", inorderTraversalTest},
    {"findDuplicateTest", findDuplicateTest},
    {"smallestRangeIITest", smallestRangeIITest},
    {"lfuCacheTest", lfuCacheTest},
    {"kthSmallestTest", kthSmallestTest},
    {"isValidBSTTest", isValidBSTTest},
    {NULL, NULL},
};