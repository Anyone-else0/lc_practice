#ifndef __PEA_TYPE_H__
#define __PEA_TYPE_H__

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode_t;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#endif