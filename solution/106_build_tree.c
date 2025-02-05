/*
 * @lc app=leetcode.cn id=106 lang=c
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
#include <stdlib.h>

/*
typedef struct StackEle_s
{
    int *pInOrder;
    int inOrderSize;
    int *pPostOrder;
    int postOrderSize;
    struct TreeNode **ppRoot;
} StackEle_t;

static struct TreeNode *createNode(void)
{
    struct TreeNode *pRoot = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    pRoot->left = NULL;
    pRoot->right = NULL;
    return pRoot;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    StackEle_t tmpEle;
    struct TreeNode *pRoot;

    tmpEle.pInOrder = inorder;
    tmpEle.inOrderSize = inorderSize;
    tmpEle.pPostOrder = postorder;
    tmpEle.postOrderSize = postorderSize;
    tmpEle.ppRoot = &pRoot;

    PeaStack_t *pStack = peaStackCreate(1000, sizeof(StackEle_t));

    while (pStack->pfEmpty(pStack) == false || tmpEle.inOrderSize != 0) {
        while (tmpEle.inOrderSize != 0) {
            struct TreeNode *pTmpRoot = createNode();
            pTmpRoot->val = tmpEle.pPostOrder[tmpEle.postOrderSize - 1];
            *(tmpEle.ppRoot) = pTmpRoot;

            int rootIdx = 0;
            for (int i = 0; i < tmpEle.inOrderSize; i++) {
                if (tmpEle.pPostOrder[tmpEle.postOrderSize - 1] == tmpEle.pInOrder[i]) {
                    rootIdx = i;
                    break;
                }
            }

            if (tmpEle.inOrderSize - rootIdx - 1 != 0) {
                StackEle_t rightEle;
                rightEle.pInOrder = &tmpEle.pInOrder[rootIdx + 1];
                rightEle.inOrderSize = tmpEle.inOrderSize - rootIdx - 1;
                rightEle.pPostOrder = &tmpEle.pPostOrder[rootIdx];
                rightEle.postOrderSize = tmpEle.postOrderSize - rootIdx - 1;
                rightEle.ppRoot = &(pTmpRoot->right);
                pStack->pfPush(pStack, &rightEle);
            }
            if (rootIdx != 0) {
                tmpEle.pInOrder = &tmpEle.pInOrder[0];
                tmpEle.inOrderSize = rootIdx;
                tmpEle.pPostOrder = &tmpEle.pPostOrder[0];
                tmpEle.postOrderSize = rootIdx;
                tmpEle.ppRoot = &(pTmpRoot->left);
            } else {
                break;
            }
        }
        if (pStack->pfEmpty(pStack) == false) {
            tmpEle = *((StackEle_t *)pStack->pfTop(pStack));
            pStack->pfPop(pStack);
        } else {
            break;
        }
    }

    return pRoot;
}
*/
// @lc code=end

