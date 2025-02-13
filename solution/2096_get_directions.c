/*
 * @lc app=leetcode.cn id=2096 lang=c
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
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

static void dfsGetPath(struct TreeNode *root, int value, struct TreeNode **path, int *pathNodeNr)
{
    PeaStack_t *pStack = peaStackCreate(100001, sizeof(struct TreeNode *));
    struct TreeNode *pNode = root;

    while (pStack->pfEmpty(pStack) == false || pNode != NULL) {
        while (pNode != NULL) {
            pStack->pfPush(pStack, &pNode);
            path[(*pathNodeNr)++] = pNode;
            if (pNode->val == value) {
                goto l_end;
            }
            pNode = pNode->left;
        }
        struct TreeNode *pLastNode = *(struct TreeNode **)pStack->pfTop(pStack);
        pNode = pLastNode->right;
        while (pNode == NULL || pNode == pLastNode) {
            pLastNode = *(struct TreeNode **)pStack->pfTop(pStack);
            pStack->pfPop(pStack);
            if (pStack->pfEmpty(pStack) == true) {
                pNode = NULL;
                break;
            }
            pNode = *(struct TreeNode **)pStack->pfTop(pStack);
            pNode = pNode->right;
            (*pathNodeNr)--;
        }
    }

l_end:
    pStack->pfDestroy(pStack);
    return;
}

char* getDirections(struct TreeNode* root, int startValue, int destValue)
{
    struct TreeNode *startPath[100001] = {0};
    int startPathNodeNr = 0;
    struct TreeNode *destPath[100001] = {0};
    int destPathNodeNr = 0;

    dfsGetPath(root, startValue, startPath, &startPathNodeNr);
    dfsGetPath(root, destValue, destPath, &destPathNodeNr);

    if (startPathNodeNr == 0 || destPathNodeNr == 0) {
        return NULL;
    }

    char *pRes = (char *)malloc(sizeof(char) * 100001);
    int resNr = 0;

    int i = startPathNodeNr - 1;
    while (i >= destPathNodeNr || startPath[i] != destPath[i]) {
        pRes[resNr++] = 'U';
        i--;
    }
    while (i < destPathNodeNr - 1) {
        if (destPath[i]->left == destPath[i + 1]) {
            pRes[resNr++] = 'L';
        } else {
            pRes[resNr++] = 'R';
        }
        i++;
    }
    pRes[resNr] = '\0';

    return pRes;
}
// @lc code=end

