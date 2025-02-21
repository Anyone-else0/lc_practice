/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层序遍历
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
#include "pea_queue.h"
#define MAX_QUE_SIZE (2000)
#define MAX_NODE_NUM (2000)
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    PeaQueue_t *pCurQue = peaQueueCreate(MAX_QUE_SIZE, sizeof(struct TreeNode *));
    PeaQueue_t *pNextQue = peaQueueCreate(MAX_QUE_SIZE, sizeof(struct TreeNode *));
    struct TreeNode *pNode = root;
    int **pRes = (int **)malloc(sizeof(int *) * MAX_NODE_NUM);
    int *pResColSizes = (int *)malloc(sizeof(int) * MAX_NODE_NUM);
    int resNr = 0;

    pCurQue->pfPushRear(pCurQue, &pNode);
    resNr++;
    pResColSizes[resNr - 1] = 0;
    pRes[resNr - 1] = (int *)malloc(sizeof(int) * pCurQue->pfNr(pCurQue));

    while (!pCurQue->pfEmpty(pCurQue)) {
        struct TreeNode *pNode = *(struct TreeNode **)pCurQue->pfFront(pCurQue);
        pRes[resNr - 1][pResColSizes[resNr - 1]] = pNode->val;
        pResColSizes[resNr - 1]++;
        if (pNode->left != NULL) {
            pNextQue->pfPushRear(pNextQue, &pNode->left);
        }
        if (pNode->right != NULL) {
            pNextQue->pfPushRear(pNextQue, &pNode->right);
        }
        pCurQue->pfPopFront(pCurQue);
        if (pCurQue->pfEmpty(pCurQue)) {
            PeaQueue_t *pTmpQue = pCurQue;
            pCurQue = pNextQue;
            pNextQue = pTmpQue;
            if (!pCurQue->pfEmpty(pCurQue)) {
                resNr++;
                pResColSizes[resNr - 1] = 0;
                pRes[resNr - 1] = (int *)malloc(sizeof(int) * pCurQue->pfNr(pCurQue));
            }
        }
    }

    *returnSize = resNr;
    *returnColumnSizes = pResColSizes;
    return pRes;
}
// @lc code=end

