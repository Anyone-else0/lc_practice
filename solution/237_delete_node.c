/*
 * @lc app=leetcode.cn id=237 lang=c
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
void deleteNode(struct ListNode* node)
{
    struct ListNode *pNext = node->next;
    node->val = pNext->val;

    node->next = pNext->next;
    free(pNext);
}
// @lc code=end

