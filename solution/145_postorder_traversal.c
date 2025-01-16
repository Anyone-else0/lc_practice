/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
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
    dfs(pNode->left, pRes, nr);
    dfs(pNode->right, pRes, nr);
    pRes[*nr] = pNode->val;
    (*nr)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *pRes = (int *)malloc(sizeof(*pRes) * 100);
    int nr = 0;
    dfs(root, pRes, &nr);
    *returnSize = nr;
    return pRes;
}*/
// @lc code=end

