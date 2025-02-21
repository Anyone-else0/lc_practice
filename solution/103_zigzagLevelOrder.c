/*
 * @lc app=leetcode.cn id=103 lang=c
 *
 * [103] 二叉树的锯齿形层序遍历
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// lc_comment_ori:#include "pea_stack.h"
// lc_comment_target_begin:pea_stack.h
#ifndef __PEA_STACK_H__
#define __PEA_STACK_H__

typedef struct PeaStackPriv PeaStackPriv_t;

typedef struct PeaStack {
    void (*pfDestroy)(struct PeaStack *pStack);
    int (*pfPop)(struct PeaStack *pStack);
    int (*pfPush)(struct PeaStack *pStack, void *pEle);
    void *(*pfTop)(struct PeaStack *pStack);
    bool (*pfEmpty)(struct PeaStack *pStack);
    int (*pfNr)(struct PeaStack *pStack);
    int (*pfCap)(struct PeaStack *pStack);
    PeaStackPriv_t *pPriv;
} PeaStack_t;

PeaStack_t *peaStackCreate(int cap, int eleSize);

#endif 

typedef struct PeaStackPriv {
    int cap;
    int nr;
    int eleSize;
    void *pBuf;
} PeaStackPriv_t;

static int peaStackPop(PeaStack_t *pStack)
{
    int rc = 0;
    if (pStack->pPriv->nr == 0) {
        rc = -1;
        goto l_end;
    } else {
        pStack->pPriv->nr--;
        goto l_end;
    }

l_end:
    return rc;
}

static int peaStackPush(PeaStack_t *pStack, void *pEle)
{
    int rc = 0;
    if (pStack->pPriv->nr >= pStack->pPriv->cap) {
        rc = -1;
        goto l_end;
    } else {
        (void)memcpy(pStack->pPriv->pBuf + pStack->pPriv->nr * pStack->pPriv->eleSize, pEle, pStack->pPriv->eleSize);
        pStack->pPriv->nr++;
        goto l_end;
    }

l_end:
    return rc;
}

static void *peaStackTop(PeaStack_t *pStack)
{
    void *pRes = NULL;
    if (pStack->pPriv->nr != 0) {
        pRes = pStack->pPriv->pBuf + (pStack->pPriv->nr - 1) * pStack->pPriv->eleSize;
    }

    return pRes;
}

static bool peaStackEmpty(PeaStack_t *pStack)
{
    return pStack->pPriv->nr == 0;
}

static int peaStackNr(PeaStack_t *pStack)
{
    return pStack->pPriv->nr;
}

static int peaStackCap(PeaStack_t *pStack)
{
    return pStack->pPriv->cap;
}

static void peaStackDestroy(PeaStack_t *pStack)
{
    if (pStack != NULL) {
        if (pStack->pPriv != NULL) {
            free(pStack->pPriv);
        }
        free(pStack);
    }
    return;
}

PeaStack_t *peaStackCreate(int cap, int eleSize)
{
    PeaStack_t *pStack = (PeaStack_t *)malloc(sizeof(*pStack));
    if (pStack == NULL) {
        printf("Stack malloc failed.\n");
        goto l_fail;
    }
    pStack->pPriv = (PeaStackPriv_t *)malloc(sizeof(*pStack->pPriv) + cap * eleSize);
    if (pStack == NULL) {
        printf("Stack priv malloc failed.\n");
        goto l_fail;
    }
    pStack->pPriv->cap = cap;
    pStack->pPriv->nr = 0;
    pStack->pPriv->eleSize = eleSize;
    pStack->pPriv->pBuf = ((char *)pStack->pPriv) + sizeof(*pStack->pPriv);

    pStack->pfDestroy = peaStackDestroy;
    pStack->pfPop = peaStackPop;
    pStack->pfPush = peaStackPush;
    pStack->pfTop = peaStackTop;
    pStack->pfEmpty = peaStackEmpty;
    pStack->pfNr = peaStackNr;
    pStack->pfCap = peaStackCap;
    goto l_end;

l_fail:
    peaStackDestroy(pStack);
l_end:
    return pStack;
} 
// lc_comment_target_end:pea_stack.h
#define MAX_STACK_SIZE (2000)
#define MAX_NODE_NUM (2000)
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    PeaStack_t *pCurStack = peaStackCreate(MAX_STACK_SIZE, sizeof(struct TreeNode *));
    PeaStack_t *pNextStack = peaStackCreate(MAX_STACK_SIZE, sizeof(struct TreeNode *));
    struct TreeNode *pNode = root;
    int **pRes = (int **)malloc(sizeof(int *) * MAX_NODE_NUM);
    int *pResColSizes = (int *)malloc(sizeof(int) * MAX_NODE_NUM);
    int resNr = 0;
    bool order = true;

    pCurStack->pfPush(pCurStack, &pNode);
    resNr++;
    pResColSizes[resNr - 1] = 0;
    pRes[resNr - 1] = (int *)malloc(sizeof(int) * pCurStack->pfNr(pCurStack));

    while (!pCurStack->pfEmpty(pCurStack)) {
        struct TreeNode *pNode = *(struct TreeNode **)pCurStack->pfTop(pCurStack);
        pRes[resNr - 1][pResColSizes[resNr - 1]] = pNode->val;
        pResColSizes[resNr - 1]++;
        if (order) {
            if (pNode->left != NULL) {
                pNextStack->pfPush(pNextStack, &pNode->left);
            }
            if (pNode->right != NULL) {
                pNextStack->pfPush(pNextStack, &pNode->right);
            }
        } else {
            if (pNode->right != NULL) {
                pNextStack->pfPush(pNextStack, &pNode->right);
            }
            if (pNode->left != NULL) {
                pNextStack->pfPush(pNextStack, &pNode->left);
            }
        }
        pCurStack->pfPop(pCurStack);
        if (pCurStack->pfEmpty(pCurStack)) {
            PeaStack_t *pTmpStack = pCurStack;
            pCurStack = pNextStack;
            pNextStack = pTmpStack;
            if (!pCurStack->pfEmpty(pCurStack)) {
                resNr++;
                pResColSizes[resNr - 1] = 0;
                pRes[resNr - 1] = (int *)malloc(sizeof(int) * pCurStack->pfNr(pCurStack));
            }
            order = !order;
        }
    }

    *returnSize = resNr;
    *returnColumnSizes = pResColSizes;
    return pRes;
}
// @lc code=end

