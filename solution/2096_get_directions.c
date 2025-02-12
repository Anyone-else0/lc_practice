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

typedef struct DrtNode {
    struct TreeNode *node;
} DrtNode_t;

char* getDirections(struct TreeNode* root, int startValue, int destValue)
{
    struct TreeNode *startPath[1000] = {0};
    int startPathNodeNr = 0;
    struct TreeNode *destPath[1000] = {0};
    int destPathNodeNr = 0;

    PeaStack_t *pStack = peaStackCreate(1000, sizeof(DrtNode_t));


}
// @lc code=end

