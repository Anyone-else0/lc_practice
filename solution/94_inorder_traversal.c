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

    struct TreeNode *pNode = root;

    PeaStack_t *pStack = peaStackCreate(100, sizeof(struct TreeNode*));
    pStack->pfPush(pStack, &pNode);

    while (pStack->pfEmpty(pStack) == false) {
        pNode = *(struct TreeNode **)pStack->pfTop(pStack);
        while (pNode->left != NULL) {
            pStack->pfPush(pStack, &pNode->left);
            pNode = pNode->left;
        }
        while (pStack->pfEmpty(pStack) == false) {
            pNode = *(struct TreeNode **)pStack->pfTop(pStack);
            pRes[nr++] = pNode->val;
            pStack->pfPop(pStack);
            if (pNode->right != NULL) {
                pStack->pfPush(pStack, &pNode->right);
                break;
            }
        }
    }

l_end:
    *returnSize = nr;
    return pRes;
}
// @lc code=end

