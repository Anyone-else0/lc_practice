/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
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
#include "pea_stack.h"

bool isValidBST(struct TreeNode* root)
{
    bool res = true;
    if (root == NULL) {
        goto l_end;
    }

    struct TreeNode *pNode = root;
    PeaStack_t *pStack = peaStackCreate(1000, sizeof(struct TreeNode *));
    int lastVal;
    bool isFirst = true;

    while (pNode != NULL || pStack->pfEmpty(pStack) == false) {
        while (pNode != NULL) {
            pStack->pfPush(pStack, &pNode);
            pNode = pNode->left;
        }
        pNode = *(struct TreeNode **)pStack->pfTop(pStack);
        pStack->pfPop(pStack);
        if (isFirst) {
            isFirst = false;
        } else if (pNode->val <= lastVal) {
            res = false;
            break;
        }
        lastVal = pNode->val;
        pNode = pNode->right;
    }

    pStack->pfDestroy(pStack);

l_end:
    return res;
}
// @lc code=end

