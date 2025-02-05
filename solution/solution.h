#ifndef __FUNC_DECLARATION_H__
#define __FUNC_DECLARATION_H__

#include <stdbool.h>

int *twoSum(int* nums, int numsSize, int target, int* returnSize);
char* longestPalindrome(char* s);
int maxArea(int* height, int heightSize);
char** generateParenthesis(int n, int* returnSize);
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);
int* searchRange(int* nums, int numsSize, int target, int* returnSize);
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
void rotate(int** matrix, int matrixSize, int* matrixColSize);
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize,
    int* returnSize, int** returnColumnSizes);
struct ListNode *reverseBetween(struct ListNode* head, int left, int right);
int* inorderTraversal(struct TreeNode* root, int* returnSize);
bool isValidBST(struct TreeNode* root);
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);
struct ListNode *detectCycle(struct ListNode *head);
int* preorderTraversal(struct TreeNode* root, int* returnSize);
int* postorderTraversal(struct TreeNode* root, int* returnSize);

typedef struct LRUCache_s LRUCache;
LRUCache *lRUCacheCreate(int capacity);
int lRUCacheGet(LRUCache* obj, int key);
void lRUCachePut(LRUCache* obj, int key, int value);
void lRUCacheFree(LRUCache* obj);

typedef struct MinStack_s MinStack;
MinStack* minStackCreate();
void minStackPush(MinStack* obj, int val);
void minStackPop(MinStack* obj);
int minStackTop(MinStack* obj);
int minStackGetMin(MinStack* obj);
void minStackFree(MinStack* obj);

int majorityElementHash(int* nums, int numsSize);
int majorityElement(int* nums, int numsSize);
int *rightSideView(struct TreeNode *root, int *returnSize);
int numIslands(char** grid, int gridSize, int* gridColSize);

typedef struct Trie_s Trie;
Trie* trieCreate(void);
void trieInsert(Trie* obj, char* word);
bool trieSearch(Trie* obj, char* word);
bool trieStartsWith(Trie* obj, char* prefix);
void trieFree(Trie* obj);

typedef struct WordDictionary_s WordDictionary;
WordDictionary* wordDictionaryCreate();
void wordDictionaryAddWord(WordDictionary* obj, char* word);
bool wordDictionarySearch(WordDictionary* obj, char* word);
void wordDictionaryFree(WordDictionary* obj);

char* shortestPalindrome(char* s);

int findKthLargestStack(int* nums, int numsSize, int k);
int findKthLargestInsert(int *nums, int numsSize, int k);
int findKthLargestBubble(int *nums, int numsSize, int k);
int findKthLargestQSort(int *nums, int numsSize, int k);
int findKthLargest(int* nums, int numsSize, int k);

// struct TreeNode* invertTree(struct TreeNode* root)
int kthSmallest(struct TreeNode* root, int k);
int findDuplicate(int* nums, int numsSize);

typedef struct Solution_s Solution;
Solution* solutionCreate(struct ListNode* head);
int solutionGetRandom(Solution* obj);
void solutionFree(Solution* obj);

int **pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes);

typedef struct LFUCache_s LFUCache;
LFUCache* lFUCacheCreate(int capacity);
int lFUCacheGet(LFUCache* obj, int key);
void lFUCachePut(LFUCache* obj, int key, int value);
void lFUCacheFree(LFUCache* obj);

int *nextGreaterElements(int* nums, int numsSize, int* returnSize);
char **topKFrequent(char **words, int wordsSize, int k, int *returnSize);
bool canPartitionKSubsets(int* nums, int numsSize, int k);
char* longestWord(char** words, int wordsSize);
char** ambiguousCoordinates(char* s, int* returnSize);
int numComponents(struct ListNode* head, int* nums, int numsSize);
int minEatingSpeed(int* piles, int pilesSize, int h);
int smallestRangeII(int* nums, int numsSize, int k);
void deleteNode(struct ListNode* node);

#endif
