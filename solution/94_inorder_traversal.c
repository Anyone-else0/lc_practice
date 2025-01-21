/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
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
#include "94_inorder_traversal.h"
#include "pea_stack.h"
#include <stdlib.h>
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *pRes = (int *)malloc(sizeof(int) * 100);
    int nr = 0;

    if (root == NULL) {
        goto l_end;
    }

    PeaStack_t *pStack = peaStackCreate(100, sizeof(struct TreeNode*));
    struct TreeNode *pNode = root;

    while (pNode != NULL || pStack->pfEmpty(pStack) == false) {
        while (pNode != NULL) {
            pStack->pfPush(pStack, &pNode);
            pNode = pNode->left;
        }
        pNode = *(struct TreeNode **)pStack->pfTop(pStack);
        pStack->pfPop(pStack);
        pRes[nr++] = pNode->val;
        pNode = pNode->right;
    }

l_end:
    *returnSize = nr;
    return pRes;
}
// @lc code=end

