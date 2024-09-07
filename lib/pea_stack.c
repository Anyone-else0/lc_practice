#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pea_stack.h"

static int peaStackPop(PeaStack_t *pStack)
{
    int rc = 0;
    if (pStack->nr == 0) {
        rc = -1;
        goto l_end;
    } else {
        pStack->nr--;
        goto l_end;
    }

l_end:
    return rc;
}

static int peaStackPush(PeaStack_t *pStack, void *pEle)
{
    int rc = 0;
    if (pStack->nr >= pStack->cap) {
        rc = -1;
        goto l_end;
    } else {
        (void)memcpy(pStack->pBuf + pStack->nr * pStack->eleSize, pEle, pStack->eleSize);
        pStack->nr++;
        goto l_end;
    }

l_end:
    return rc;
}

static void *peaStackTop(PeaStack_t *pStack)
{
    void *pRes = NULL;
    if (pStack->nr != 0) {
        pRes = pStack->pBuf + (pStack->nr - 1) * pStack->eleSize;
    }

    return pRes;
}

static bool peaStackEmpty(PeaStack_t *pStack)
{
    return pStack->nr == 0;
}

static void peaStackDestroy(PeaStack_t *pStack)
{
    free(pStack);
    return;
}

PeaStack_t *peaStackCreate(int cap, int eleSize)
{
    PeaStack_t *pStack = (PeaStack_t *)malloc(sizeof(*pStack) + cap * eleSize);
    if (pStack == NULL) {
        goto l_end;
    }
    pStack->cap = cap;
    pStack->nr = 0;
    pStack->eleSize = eleSize;
    pStack->pBuf = ((void *)pStack) + sizeof(*pStack);

    pStack->pfDestroy = peaStackDestroy;
    pStack->pfPop = peaStackPop;
    pStack->pfPush = peaStackPush;
    pStack->pfTop = peaStackTop;
    pStack->pfEmpty = peaStackEmpty;

l_end:
    return pStack;
}