/*
 * @lc app=leetcode.cn id=103 lang=c
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include "pea_stack.h"
#define MAX_STACK_SIZE (2000)
#define MAX_NODE_NUM (2000)
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    PeaStack_t *pCurStack = peaStackCreate(MAX_STACK_SIZE, sizeof(struct TreeNode *));
    PeaStack_t *pNextStack = peaStackCreate(MAX_STACK_SIZE, sizeof(struct TreeNode *));
    struct TreeNode *pNode = root;
    int **pRes = (int **)malloc(sizeof(int *) * MAX_NODE_NUM);
    int *pResColSizes = (int *)malloc(sizeof(int) * MAX_NODE_NUM);
    int resNr = 0;
    bool order = true;

    pCurStack->pfPush(pCurStack, &pNode);
    resNr++;
    pResColSizes[resNr - 1] = 0;
    pRes[resNr - 1] = (int *)malloc(sizeof(int) * pCurStack->pfNr(pCurStack));

    while (!pCurStack->pfEmpty(pCurStack)) {
        struct TreeNode *pNode = *(struct TreeNode **)pCurStack->pfTop(pCurStack);
        pRes[resNr - 1][pResColSizes[resNr - 1]] = pNode->val;
        pResColSizes[resNr - 1]++;
        if (order) {
            if (pNode->left != NULL) {
                pNextStack->pfPush(pNextStack, &pNode->left);
            }
            if (pNode->right != NULL) {
                pNextStack->pfPush(pNextStack, &pNode->right);
            }
        } else {
            if (pNode->right != NULL) {
                pNextStack->pfPush(pNextStack, &pNode->right);
            }
            if (pNode->left != NULL) {
                pNextStack->pfPush(pNextStack, &pNode->left);
            }
        }
        pCurStack->pfPop(pCurStack);
        if (pCurStack->pfEmpty(pCurStack)) {
            PeaStack_t *pTmpStack = pCurStack;
            pCurStack = pNextStack;
            pNextStack = pTmpStack;
            if (!pCurStack->pfEmpty(pCurStack)) {
                resNr++;
                pResColSizes[resNr - 1] = 0;
                pRes[resNr - 1] = (int *)malloc(sizeof(int) * pCurStack->pfNr(pCurStack));
            }
            order = !order;
        }
    }

    *returnSize = resNr;
    *returnColumnSizes = pResColSizes;
    return pRes;
}
// @lc code=end

