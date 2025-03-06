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
#include "pea_stack.h"
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
/*
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
}*/

typedef struct StackEle
{
    struct ListNode *pList;
    struct TreeNode **ppRoot;
} StackEle_t;

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }

    struct TreeNode *pRes;
    struct TreeNode **ppCurRoot = &pRes;

    PeaStack_t *pStack = peaStackCreate(1000, sizeof(StackEle_t));
    struct ListNode *pList = head;
    while (pList != NULL || pStack->pfEmpty(pStack) == false) {
        while (pList != NULL) {
            struct ListNode *pMid = getPartition(pList);
            struct TreeNode *pNewRoot = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            pNewRoot->val = pMid->val;
            pNewRoot->left = NULL;
            pNewRoot->right = NULL;
            *ppCurRoot = pNewRoot;
            // 左
            if (pMid == pList) {
                pList = NULL;
            } else {
                pList = pList;
                ppCurRoot = &pNewRoot->left;
            }
            // 右
            if (pMid->next != NULL) {
                StackEle_t ele = {.pList = pMid->next, .ppRoot = &pNewRoot->right};
                pStack->pfPush(pStack, &ele);
            }
        }

        if (pStack->pfEmpty(pStack) == false) {
            StackEle_t ele = *(StackEle_t *)pStack->pfTop(pStack);
            pStack->pfPop(pStack);
            pList = ele.pList;
            ppCurRoot = ele.ppRoot;
        } else {
            pList = NULL;
        }
    }

    return pRes;
}
// @lc code=end

