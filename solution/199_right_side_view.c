/*
 * @lc app=leetcode.cn id=199 lang=c
 *
 * [199] 二叉树的右视图
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "pea_queue.h"

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    int *pRes = (int *)malloc(sizeof(int) * 100);
    int nr = 0;

    PeaQueue_t *pQue1 = peaQueueCreate(20, sizeof(struct TreeNode *));
    PeaQueue_t *pQue2 = peaQueueCreate(20, sizeof(struct TreeNode *));

    PeaQueue_t *pCurQue = pQue1;
    PeaQueue_t *pNextQue = pQue2;

    if (root != NULL) {
        pCurQue->pfPush(pCurQue, &root);
    }

    while (pCurQue->pfEmpty(pCurQue) == false) {
        struct TreeNode *pTmpNode = *((struct TreeNode **)pCurQue->pfFront(pCurQue));
        if (pTmpNode->left != NULL) {
            pNextQue->pfPush(pNextQue, &(pTmpNode->left));
        }
        if (pTmpNode->right != NULL) {
            pNextQue->pfPush(pNextQue, &(pTmpNode->right));
        }
        pCurQue->pfPop(pCurQue);
        if (pCurQue->pfEmpty(pCurQue) != false) {
            pRes[nr++] = pTmpNode->val;
            PeaQueue_t *pTmpQue = pCurQue;
            pCurQue = pNextQue;
            pNextQue = pTmpQue;
        }
    }

    *returnSize = nr;
    return pRes;
}
// @lc code=end

