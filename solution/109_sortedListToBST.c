/*
 * @lc app=leetcode.cn id=109 lang=c
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static struct ListNode *getPartition(struct ListNode* head)
{
    struct ListNode *pSlow = head;
    struct ListNode *pFast = head;
    struct ListNode *pPrev = NULL;
    while (pFast && pFast->next) {
        pPrev = pSlow;
        pSlow = pSlow->next;
        pFast = pFast->next->next;
    }

    if (pPrev) {
        pPrev->next = NULL;
    }

    return pSlow;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *pRoot = getPartition(head);
    struct TreeNode *pNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    pNode->val = pRoot->val;

    if (pRoot == head) {
        pNode->left = NULL;
    } else {
        pNode->left = sortedListToBST(head);
    }
    if (pRoot->next == NULL) {
        pNode->right = NULL;
    } else {
        pNode->right = sortedListToBST(pRoot->next);
    }

    return pNode;
}
// @lc code=end

