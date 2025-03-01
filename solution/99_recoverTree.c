/*
 * @lc app=leetcode.cn id=99 lang=c
 *
 * [99] 恢复二叉搜索树
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

void recoverTree(struct TreeNode* root)
{
    PeaStack_t *pStack = peaStackCreate(1000, sizeof(PeaStack_t *));
    struct TreeNode *pNode = root;
    struct TreeNode *pOrder[1000];
    int orderNr = 0;
    int flag = 0;
    int tgtIdx;

    while (pNode != NULL || pStack->pfEmpty(pStack) == false) {
        while (pNode != NULL) {
            pStack->pfPush(pStack, &pNode);
            pNode = pNode->left;
        }

        pNode = *(struct TreeNode **)pStack->pfTop(pStack);
        pOrder[orderNr++] = pNode;

        if (flag == 0 && orderNr > 1 && pOrder[orderNr - 1]->val < pOrder[orderNr - 2]->val) {
            tgtIdx = orderNr - 2;
            flag++;
        } else if (flag == 1 && pOrder[orderNr - 1]->val < pOrder[orderNr - 2]->val) {
            flag++;
            break;
        }

        pStack->pfPop(pStack);
        pNode = pNode->right;
    }

    if (flag == 2) {
        int tmp = pOrder[orderNr - 1]->val;
        pOrder[orderNr - 1]->val = pOrder[tgtIdx]->val;
        pOrder[tgtIdx]->val = tmp;
    } else {
        int tmp = pOrder[tgtIdx + 1]->val;
        pOrder[tgtIdx + 1]->val = pOrder[tgtIdx]->val;
        pOrder[tgtIdx]->val = tmp;
    }

    pStack->pfDestroy(pStack);

    return;
}
// @lc code=end

