/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
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
    pRes[*nr] = pNode->val;
    (*nr)++;
    dfs(pNode->left, pRes, nr);
    dfs(pNode->right, pRes, nr);
    return;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *pRes = (int *)malloc(sizeof(int) * 100);
    int nr = 0;
    dfs(root, pRes, &nr);
    *returnSize = nr;
    return pRes;
}*/
#include "pea_stack.h"

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *pRes = (int *)malloc(sizeof(int) * 100);
    int nr = 0;

    if (root == NULL) {
        goto l_end;
    }

    PeaStack_t *pStack = peaStackCreate(100, sizeof(struct TreeNode *));
    struct TreeNode *pNode = root;

    while (pStack->pfEmpty(pStack) == false || pNode != NULL) {
        while (pNode != NULL) {
            pRes[nr++] = pNode->val;
            pStack->pfPush(pStack, &pNode->right);
            pNode = pNode->left;
        }
        pNode = *(struct TreeNode **)pStack->pfTop(pStack);
        pStack->pfPop(pStack);
    }
    pStack->pfDestroy(pStack);

l_end:
    *returnSize = nr;
    return pRes;
}

// @lc code=end

