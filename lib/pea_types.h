#ifndef __PEA_TYPE_H__
#define __PEA_TYPE_H__

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode_t;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode_t;

#endif