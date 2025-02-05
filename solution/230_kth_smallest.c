/*
 * @lc app=leetcode.cn id=230 lang=c
 *
 * [230] 二叉搜索树中第 K 小的元素
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
#include <stddef.h>

int kthSmallest(struct TreeNode* root, int k)
{
    PeaStack_t *pStack = peaStackCreate(1000, sizeof(struct TreeNode *));
    struct TreeNode *pNode = root;
    int cnt = 0;
    int res = -1;

    while (pNode != NULL || pStack->pfEmpty(pStack) == false) {
        while (pNode != NULL) {
            pStack->pfPush(pStack, &pNode);
            pNode = pNode->left;
        }

        pNode = *(struct TreeNode **)pStack->pfTop(pStack);
        pStack->pfPop(pStack);
        cnt++;
        if (cnt == k) {
            res = pNode->val;
            goto l_end;
        }
        pNode = pNode->right;
    }

l_end:
    pStack->pfDestroy(pStack);
    return res;
}
// @lc code=end

