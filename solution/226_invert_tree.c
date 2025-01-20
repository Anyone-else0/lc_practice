/*
 * @lc app=leetcode.cn id=226 lang=c
 *
 * [226] 翻转二叉树
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
/*
static void dfs(struct TreeNode *pNode)
{
    if (pNode == NULL) {
        return;
    }
    struct TreeNode *pTmp = pNode->left;
    pNode->left = pNode->right;
    pNode->right = pTmp;
    dfs(pNode->left);
    dfs(pNode->right);
    return;
}

struct TreeNode* invertTree(struct TreeNode* root)
{
    dfs(root);
    return root;
}*/
// @lc code=end

