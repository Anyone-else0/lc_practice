#include <stdio.h>
#include <string.h>
#include "pea_stack_ut.h"
#include "pea_stack.h"

static void peaStackTest(void)
{
    {
        int num[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
        PeaStack_t *pUtStack = peaStackCreate(5, sizeof(int));
        UT_ASSERT(pUtStack != NULL);
        UT_ASSERT(pUtStack->nr == 0);
        UT_ASSERT(pUtStack->cap == 5);
        int rc;
        int *pTop = (int *)pUtStack->pfTop(pUtStack);
        UT_ASSERT(pTop == NULL);
        for (int i = 0; i < 5; i++)
        {
            rc = pUtStack->pfPush(pUtStack, &num[i]);
            UT_ASSERT(rc == 0);
        }
        UT_ASSERT(pUtStack->nr == pUtStack->cap);
        pTop = (int *)pUtStack->pfTop(pUtStack);
        UT_ASSERT(*pTop == 5);
        int tmp = 100;
        rc = pUtStack->pfPush(pUtStack, &tmp);
        UT_ASSERT(rc != 0);
        pTop = pUtStack->pfTop(pUtStack);
        UT_ASSERT(*pTop == 5);
        for (int i = 4; i >= 0; i--)
        {
            rc = pUtStack->pfPop(pUtStack);
            UT_ASSERT(rc == 0);
        }
        rc = pUtStack->pfPop(pUtStack);
        UT_ASSERT(rc != 0);
    }
}

UtCase_t gPeaStackSuit[] = {
    {"peaStackTest", peaStackTest},
    {NULL, NULL}
};