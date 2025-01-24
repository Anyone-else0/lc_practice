/*
 * @lc app=leetcode.cn id=105 lang=c
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

#include "105_build_tree.h"
#include <stddef.h>
#include <stdlib.h>

static struct TreeNode *createNode(void)
{
    struct TreeNode *pRoot = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    pRoot->left = NULL;
    pRoot->right = NULL;
    return pRoot;
}

struct TreeNode *buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    struct TreeNode *pRoot = NULL;
    if (preorderSize <= 0) {
        goto l_end;
    }

    pRoot = createNode();
    pRoot->val = preorder[0];
    int rootIdx = 0;
    for (int i = 1; i < inorderSize; i++) {
        if (preorder[0] == inorder[i]) {
            rootIdx = i;
            break;
        }
    }

    int *pLeftPreOrder = &preorder[1];
    int leftPreOrderSize = rootIdx;
    int *pRightPreOrder = &preorder[1 + rootIdx];
    int rightPreOrderSize = preorderSize - 1 - rootIdx;
    int *pLeftInorder = &inorder[0];
    int leftInorderSize= rootIdx;
    int *pRightInorder = &inorder[rootIdx + 1];
    int rightInOrderSize = inorderSize - 1 - rootIdx;

    pRoot->left = buildTree(pLeftPreOrder, leftPreOrderSize, pLeftInorder, leftInorderSize);
    pRoot->right = buildTree(pRightPreOrder, rightPreOrderSize, pRightInorder, rightInOrderSize);

l_end:
    return pRoot;
}

// @lc code=end

