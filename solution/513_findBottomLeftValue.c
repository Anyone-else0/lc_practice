/*
 * @lc app=leetcode.cn id=513 lang=c
 *
 * [513] 找树左下角的值
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
#include "pea_queue.h"
int findBottomLeftValue(struct TreeNode* root)
{
    int rc = 0;
    if (root == NULL)
    {
        goto l_end;
    }
    PeaQueue_t *pQue1 = peaQueueCreate(1000, sizeof(struct TreeNode *));
    PeaQueue_t *pQue2 = peaQueueCreate(1000, sizeof(struct TreeNode *));
    PeaQueue_t *pQuePush = pQue1;
    PeaQueue_t *pQuePop = pQue2;

    pQuePop->pfPushRear(pQuePop, &root);
    rc = root->val;
    while (pQuePop->pfEmpty(pQuePop) == false) {
        struct TreeNode *pCurNode = *(struct TreeNode **)pQuePop->pfFront(pQuePop);
        rc = pCurNode->val;
        while (pQuePop->pfEmpty(pQuePop) == false) {
            pCurNode = *(struct TreeNode **)pQuePop->pfFront(pQuePop);
            pQuePop->pfPopFront(pQuePop);
            if (pCurNode->left != NULL) {
                pQuePush->pfPushRear(pQuePush, &pCurNode->left);
            }
            if (pCurNode->right != NULL) {
                pQuePush->pfPushRear(pQuePush, &pCurNode->right);
            }
        }
        PeaQueue_t *pQueTmp = pQuePop;
        pQuePop = pQuePush;
        pQuePush = pQueTmp;
    }

l_end:
    return rc;
}
// @lc code=end

