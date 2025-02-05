#include "pea_stack.h"

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
    PeaStack_t *pStack = (PeaStack_t *)malloc(sizeof(*pStack) + cap * eleSize);
    if (pStack == NULL) {
        printf("Stack malloc failed.\n");
        goto l_fail;
    }
    pStack->pPriv = (PeaStackPriv_t *)malloc(sizeof(*pStack->pPriv));
    if (pStack == NULL) {
        printf("Stack priv malloc failed.\n");
        goto l_fail;
    }
    pStack->pPriv->cap = cap;
    pStack->pPriv->nr = 0;
    pStack->pPriv->eleSize = eleSize;
    pStack->pPriv->pBuf = ((void *)pStack) + sizeof(*pStack);

    pStack->pfDestroy = peaStackDestroy;
    pStack->pfPop = peaStackPop;
    pStack->pfPush = peaStackPush;
    pStack->pfTop = peaStackTop;
    pStack->pfEmpty = peaStackEmpty;
    goto l_end;

l_fail:
    peaStackDestroy(pStack);
l_end:
    return pStack;
}