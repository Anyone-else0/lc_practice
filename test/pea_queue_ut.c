#include "pea_queue_ut.h"
#include "pea_queue.h"

static void peaQueueTest(void)
{
    {
        int num[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
        PeaQueue_t *pUtQue = peaQueueCreate(5, sizeof(int));
        UT_ASSERT(pUtQue != NULL);
        int rc;
        int *pEle = (int *)pUtQue->pfFront(pUtQue);
        UT_ASSERT(pEle == NULL);
        pEle = (int *)pUtQue->pfRear(pUtQue);
        UT_ASSERT(pEle == NULL);
        for (int i = 0; i < 5; i++)
        {
            rc = pUtQue->pfPushRear(pUtQue, &num[i]);
            UT_ASSERT(rc == 0);
        }
        pEle = (int *)pUtQue->pfRear(pUtQue);
        UT_ASSERT(*pEle == 5);
        pEle = (int *)pUtQue->pfFront(pUtQue);
        UT_ASSERT(*pEle == 1);
        int tmp = 100;
        rc = pUtQue->pfPushRear(pUtQue, &tmp);
        UT_ASSERT(rc != 0);
        pEle = pUtQue->pfRear(pUtQue);
        UT_ASSERT(*pEle == 5);
        for (int i = 4; i >= 0; i--)
        {
            rc = pUtQue->pfPopFront(pUtQue);
            UT_ASSERT(rc == 0);
        }
        pEle = (int *)pUtQue->pfRear(pUtQue);
        UT_ASSERT(pEle == NULL);
        pEle = (int *)pUtQue->pfFront(pUtQue);
        UT_ASSERT(pEle == NULL);
        UT_ASSERT(pUtQue->pfEmpty(pUtQue) == true);
        pUtQue->pfDestroy(pUtQue);
    }
}

UtCase_t gPeaQueueSuit[] = {
    {"peaQueueTest", peaQueueTest},
    {NULL, NULL}
};