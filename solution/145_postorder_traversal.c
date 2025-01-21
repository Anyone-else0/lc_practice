/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
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
/*
static void dfs(struct TreeNode *pNode, int *pRes, int *nr)
{
    if (pNode == NULL) {
        return;
    }
    dfs(pNode->left, pRes, nr);
    dfs(pNode->right, pRes, nr);
    pRes[*nr] = pNode->val;
    (*nr)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *pRes = (int *)malloc(sizeof(*pRes) * 100);
    int nr = 0;
    dfs(root, pRes, &nr);
    *returnSize = nr;
    return pRes;
}*/

#include "144_preorder_traversal.h"
#include "pea_stack.h"
#include <stdlib.h>

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *pRes = (int *)malloc(sizeof(*pRes) * 100);
    int nr = 0;

    if (root == NULL) {
        goto l_end;
    }

    PeaStack_t *pStack = peaStackCreate(100, sizeof(struct TreeNode *));
    struct TreeNode *pNode = root;
    struct TreeNode *pTmp = NULL;

    while (pNode != NULL || pStack->pfEmpty(pStack) == false) {
        while (pNode != NULL && pNode != pTmp) {
            pStack->pfPush(pStack, &pNode);
            pNode = pNode->left;
        }
        pNode = *(struct TreeNode **)pStack->pfTop(pStack);
        if (pNode->right == NULL || pNode->right == pTmp) {
            pStack->pfPop(pStack);
            pRes[nr++] = pNode->val;
            pTmp = pNode;
        }
        if (pStack->pfEmpty(pStack) == false) {
            pNode = *(struct TreeNode **)pStack->pfTop(pStack);
            pNode = pNode->right;
        } else {
            pNode = NULL;
        }
    }

    pStack->pfDestroy(pStack);

l_end:
    *returnSize = nr;
    return pRes;
}
// @lc code=end

