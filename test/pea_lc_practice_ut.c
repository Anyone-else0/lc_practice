#include "pea_lc_practice_ut.h"
#include "solution.h"

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

static void buildTreeTest(void)
{
    {
        int preorder[] = {3, 9, 20, 15, 7};
        int preorderSize = sizeof(preorder) / sizeof(preorder[0]);
        int inorder[] = {9, 3, 15, 20, 7};
        int inorderSize = sizeof(inorder) / sizeof(inorder[0]);
        struct TreeNode *pRoot = buildTree(preorder, preorderSize, inorder, inorderSize);
        UT_ASSERT(pRoot->val == 3);
        UT_ASSERT(pRoot->left->val == 9);
        UT_ASSERT(pRoot->right->val == 20);
        UT_ASSERT(pRoot->right->left->val == 15);
        UT_ASSERT(pRoot->right->right->val == 7);
        free(pRoot->left);
        free(pRoot->right->left);
        free(pRoot->right->right);
        free(pRoot->right);
        free(pRoot);
    }
    {
        int preorder[] = {1, 2};
        int preorderSize = sizeof(preorder) / sizeof(preorder[0]);
        int inorder[] = {2, 1};
        int inorderSize = sizeof(inorder) / sizeof(inorder[0]);
        struct TreeNode *pRoot = buildTree(preorder, preorderSize, inorder, inorderSize);
        UT_ASSERT(pRoot->val == 1);
        UT_ASSERT(pRoot->left->val == 2);
        free(pRoot->left);
        free(pRoot);
    }
}

static void rightSideViewTest(void)
{
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 1;
        root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->val = 2;
        root->left->left = NULL;
        root->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->right->val = 5;
        root->left->right->left = NULL;
        root->left->right->right = NULL;
        root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->val = 3;
        root->right->left = NULL;
        root->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->right->val = 4;
        root->right->right->left = NULL;
        root->right->right->right = NULL;

        int returnSize;
        int *res = rightSideView(root, &returnSize);
        int exp[] = {1, 3, 4};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == exp[i]);
        }
        free(res);
        free(root->left->right);
        free(root->left);
        free(root->right->right);
        free(root->right);
        free(root);
    }
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 1;
        root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->val = 2;
        root->left->left = NULL;
        root->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->right->val = 5;
        root->left->right->left = NULL;
        root->left->right->right = NULL;
        root->right = NULL;

        int returnSize;
        int *res = rightSideView(root, &returnSize);
        int exp[] = {1, 2, 5};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == exp[i]);
        }
    }
}

static void solutionGetRandomTest(void)
{
    {
        int nums[] = {1, 2, 3};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        struct ListNode *head = singleListCreateFromNums(nums, numsSize);
        Solution *obj = solutionCreate(head);
        int randomVal = solutionGetRandom(obj);
        UT_ASSERT(randomVal >= 1 && randomVal <= 3);
        solutionFree(obj);
        singleListFree(head);
    }
    {
        int nums[] = {1};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        struct ListNode *head = singleListCreateFromNums(nums, numsSize);
        Solution *obj = solutionCreate(head);
        int randomVal = solutionGetRandom(obj);
        UT_ASSERT(randomVal == 1);
        solutionFree(obj);
        singleListFree(head);
    }
    {
        int nums[] = {1, 2, 3};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        struct ListNode *head = singleListCreateFromNums(nums, numsSize);
        Solution *obj = solutionCreate(head);
        int count[3] = {0, 0, 0};
        int iterations = 10000;
        for (int i = 0; i < iterations; i++) {
            int randomVal = solutionGetRandom(obj);
            count[randomVal - 1]++;
        }
        for (int i = 0; i < 3; i++) {
            UT_ASSERT(count[i] > iterations / 4 && count[i] < iterations / 2);
        }
        solutionFree(obj);
        singleListFree(head);
    }
}

static void rotateTest(void)
{
    {
        {
            int matrix[][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };
            int matrixSize = sizeof(matrix) / sizeof(matrix[0]);
            int matrixColSize = sizeof(matrix[0]) / sizeof(matrix[0][0]);
            int exp[][3] = {
                {7, 4, 1},
                {8, 5, 2},
                {9, 6, 3}
            };
            int i, j;
            int **ppMatrix = (int **)malloc(matrixSize * sizeof(int *));
            for (i = 0; i < matrixSize; i++) {
                ppMatrix[i] = (int *)malloc(matrixColSize * sizeof(int));
                memcpy(ppMatrix[i], matrix[i], matrixColSize * sizeof(int));
            }
            rotate(ppMatrix, matrixSize, &matrixColSize);
            for (i = 0; i < matrixSize; i++) {
                for (j = 0; j < matrixColSize; j++) {
                    UT_ASSERT(ppMatrix[i][j] == exp[i][j]);
                }
                free(ppMatrix[i]);
            }
            free(ppMatrix);
        }
        {
            int matrix[][4] = {
                {5, 1, 9, 11},
                {2, 4, 8, 10},
                {13, 3, 6, 7},
                {15, 14, 12, 16}
            };
            int matrixSize = sizeof(matrix) / sizeof(matrix[0]);
            int matrixColSize = sizeof(matrix[0]) / sizeof(matrix[0][0]);
            int exp[][4] = {
                {15, 13, 2, 5},
                {14, 3, 4, 1},
                {12, 6, 8, 9},
                {16, 7, 10, 11}
            };
            int i, j;
            int **ppMatrix = (int **)malloc(matrixSize * sizeof(int *));
            for (i = 0; i < matrixSize; i++) {
                ppMatrix[i] = (int *)malloc(matrixColSize * sizeof(int));
                memcpy(ppMatrix[i], matrix[i], matrixColSize * sizeof(int));
            }
            rotate(ppMatrix, matrixSize, &matrixColSize);
            for (i = 0; i < matrixSize; i++) {
                for (j = 0; j < matrixColSize; j++) {
                    UT_ASSERT(ppMatrix[i][j] == exp[i][j]);
                }
                free(ppMatrix[i]);
            }
            free(ppMatrix);
        }
    }
}

static void deleteNodeTest(void)
{
    {
        struct ListNode *pHead = singleListCreateFromNums((int[]){4, 5, 1, 9}, 4);
        struct ListNode *pNode = pHead->next;
        deleteNode(pNode);
        int exp[] = {4, 1, 9};
        int i = 0;
        while (pHead) {
            UT_ASSERT(pHead->val == exp[i]);
            pHead = pHead->next;
            i++;
        }
        UT_ASSERT(i == sizeof(exp) / sizeof(exp[0]));
        singleListFree(pHead);
    }
    {
        struct ListNode *pHead = singleListCreateFromNums((int[]){4, 5, 1, 9}, 4);
        struct ListNode *pNode = pHead;
        deleteNode(pNode);
        int exp[] = {5, 1, 9};
        int i = 0;
        while (pHead) {
            UT_ASSERT(pHead->val == exp[i]);
            pHead = pHead->next;
            i++;
        }
        UT_ASSERT(i == sizeof(exp) / sizeof(exp[0]));
        singleListFree(pHead);
    }
}

static void findingUsersActiveMinutesTest(void)
{
    {
        int logsArr[][2] = {
            {0, 5},
            {1, 2},
            {0, 2},
            {0, 5},
            {1, 3}
        };
        int logsSize = sizeof(logsArr) / sizeof(logsArr[0]);
        int logsColSize = sizeof(logsArr[0]) / sizeof(logsArr[0][0]);
        int **logs = (int **)malloc(logsSize * sizeof(int *));
        for (int i = 0; i < logsSize; i++) {
            logs[i] = logsArr[i];
        }
        int k = 5;
        int returnSize;
        int *res = findingUsersActiveMinutes(logs, logsSize, &logsColSize, k, &returnSize);
        int exp[] = {0, 2, 0, 0, 0};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == exp[i]);
        }
        free(res);
        free(logs);
    }
    {
        int logsArr[][2] = {
            {1, 1},
            {2, 2},
            {2, 3}
        };
        int logsSize = sizeof(logsArr) / sizeof(logsArr[0]);
        int logsColSize = sizeof(logsArr[0]) / sizeof(logsArr[0][0]);
        int **logs = (int **)malloc(logsSize * sizeof(int *));
        for (int i = 0; i < logsSize; i++) {
            logs[i] = logsArr[i];
        }
        int k = 4;
        int returnSize;
        int *res = findingUsersActiveMinutes(logs, logsSize, &logsColSize, k, &returnSize);
        int exp[] = {1, 1, 0, 0};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(res[i] == exp[i]);
        }
        free(res);
        free(logs);
    }
}

static void getDirectionsTest(void)
{
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = 5;
        root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->left->val = 1;
        root->left->left = NULL;
        root->left->right = NULL;
        root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->val = 2;
        root->right->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->left->val = 3;
        root->right->left->left = NULL;
        root->right->left->right = NULL;
        root->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->right->right->val = 6;
        root->right->right->left = NULL;
        root->right->right->right = NULL;

        char *res = getDirections(root, 1, 2);
        char exp[] = "UR";
        UT_ASSERT(strcmp(res, exp) == 0);

        free(res);
        free(root->right->right);
        free(root->right->left);
        free(root->right);
        free(root->left);
        free(root);
    }
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

        char *res = getDirections(root, 1, 3);
        char exp[] = "UR";
        UT_ASSERT(strcmp(res, exp) == 0);

        free(res);
        free(root->right);
        free(root->left);
        free(root);
    }
}

static void partitionTest(void)
{
    {
        int nums[] = {1, 4, 3, 2, 5, 2};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int x = 3;
        struct ListNode *pHead = singleListCreateFromNums(nums, numsSize);
        struct ListNode *pRes = partition(pHead, x);
        int exp[] = {1, 2, 2, 4, 3, 5};
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
        int nums[] = {2, 1};
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int x = 2;
        struct ListNode *pHead = singleListCreateFromNums(nums, numsSize);
        struct ListNode *pRes = partition(pHead, x);
        int exp[] = {1, 2};
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

static struct TreeNode* createTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static void levelOrderTest(void)
{
    {
        struct TreeNode* root = createTreeNode(3);
        root->left = createTreeNode(9);
        root->right = createTreeNode(20);
        root->right->left = createTreeNode(15);
        root->right->right = createTreeNode(7);

        int returnSize;
        int* returnColumnSizes;
        int** res = levelOrder(root, &returnSize, &returnColumnSizes);

        int exp[][3] = {{3}, {9, 20}, {15, 7}};
        int expSizes[] = {1, 2, 2};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(returnColumnSizes[i] == expSizes[i]);
            for (int j = 0; j < returnColumnSizes[i]; j++) {
                UT_ASSERT(res[i][j] == exp[i][j]);
            }
            free(res[i]);
        }
        free(res);
        free(returnColumnSizes);
        free(root->right->right);
        free(root->right->left);
        free(root->right);
        free(root->left);
        free(root);
    }
    {
        struct TreeNode* root = NULL;

        int returnSize;
        int* returnColumnSizes;
        int** res = levelOrder(root, &returnSize, &returnColumnSizes);

        UT_ASSERT(returnSize == 0);
        UT_ASSERT(res == NULL);
        UT_ASSERT(returnColumnSizes == NULL);
    }
    {
        struct TreeNode* root = createTreeNode(1);

        int returnSize;
        int* returnColumnSizes;
        int** res = levelOrder(root, &returnSize, &returnColumnSizes);

        int exp[][1] = {{1}};
        int expSizes[] = {1};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(returnColumnSizes[i] == expSizes[i]);
            for (int j = 0; j < returnColumnSizes[i]; j++) {
                UT_ASSERT(res[i][j] == exp[i][j]);
            }
            free(res[i]);
        }
        free(res);
        free(returnColumnSizes);
        free(root);
    }
}

static void zigzagLevelOrderTest(void)
{
    {
        struct TreeNode* root = createTreeNode(3);
        root->left = createTreeNode(9);
        root->right = createTreeNode(20);
        root->right->left = createTreeNode(15);
        root->right->right = createTreeNode(7);

        int returnSize;
        int* returnColumnSizes;
        int** res = zigzagLevelOrder(root, &returnSize, &returnColumnSizes);

        int exp[][3] = {{3}, {20, 9}, {15, 7}};
        int expSizes[] = {1, 2, 2};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(returnColumnSizes[i] == expSizes[i]);
            for (int j = 0; j < returnColumnSizes[i]; j++) {
                UT_ASSERT(res[i][j] == exp[i][j]);
            }
            free(res[i]);
        }
        free(res);
        free(returnColumnSizes);
        free(root->right->right);
        free(root->right->left);
        free(root->right);
        free(root->left);
        free(root);
    }
    {
        struct TreeNode* root = NULL;

        int returnSize;
        int* returnColumnSizes;
        int** res = zigzagLevelOrder(root, &returnSize, &returnColumnSizes);

        UT_ASSERT(returnSize == 0);
        UT_ASSERT(res == NULL);
        UT_ASSERT(returnColumnSizes == NULL);
    }
    {
        struct TreeNode* root = createTreeNode(1);

        int returnSize;
        int* returnColumnSizes;
        int** res = zigzagLevelOrder(root, &returnSize, &returnColumnSizes);

        int exp[][1] = {{1}};
        int expSizes[] = {1};
        UT_ASSERT(returnSize == sizeof(exp) / sizeof(exp[0]));
        for (int i = 0; i < returnSize; i++) {
            UT_ASSERT(returnColumnSizes[i] == expSizes[i]);
            for (int j = 0; j < returnColumnSizes[i]; j++) {
                UT_ASSERT(res[i][j] == exp[i][j]);
            }
            free(res[i]);
        }
        free(res);
        free(returnColumnSizes);
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
    {"buildTreeTest", buildTreeTest},
    {"rightSideViewTest", rightSideViewTest},
    {"solutionGetRandomTest", solutionGetRandomTest},
    {"rotateTest", rotateTest},
    {"deleteNodeTest", deleteNodeTest},
    {"findingUsersActiveMinutesTest", findingUsersActiveMinutesTest},
    {"getDirectionsTest", getDirectionsTest},
    {"partitionTest", partitionTest},
    {"levelOrderTest", levelOrderTest},
    {"zigzagLevelOrderTest", zigzagLevelOrderTest},
    {NULL, NULL},
};