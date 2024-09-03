#include <stdio.h>
#include <string.h>
#include "pea_queue_ut.h"
#include "pea_queue.h"

static void peaQueueTest(void)
{
    {
        int num[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
        PeaQueue_t *pUtQue = peaQueueCreate(5, sizeof(int));
        UT_ASSERT(pUtQue != NULL);
        UT_ASSERT(pUtQue->front == pUtQue->rear);
        UT_ASSERT(pUtQue->cap == 5);
        int rc;
        int *pEle = (int *)peaQueueFront(pUtQue);
        UT_ASSERT(pEle == NULL);
        pEle = (int *)peaQueueRear(pUtQue);
        UT_ASSERT(pEle == NULL);
        for (int i = 0; i < 5; i++)
        {
            rc = peaQueuePush(pUtQue, &num[i]);
            UT_ASSERT(rc == 0);
        }
        pEle = (int *)peaQueueRear(pUtQue);
        UT_ASSERT(*pEle == 5);
        pEle = (int *)peaQueueFront(pUtQue);
        UT_ASSERT(*pEle == 1);
        int tmp = 100;
        rc = peaQueuePush(pUtQue, &tmp);
        UT_ASSERT(rc != 0);
        pEle = peaQueueRear(pUtQue);
        UT_ASSERT(*pEle == 5);
        for (int i = 4; i >= 0; i--)
        {
            rc = peaQueuePop(pUtQue);
            UT_ASSERT(rc == 0);
        }
        pEle = (int *)peaQueueRear(pUtQue);
        UT_ASSERT(pEle == NULL);
        pEle = (int *)peaQueueFront(pUtQue);
        UT_ASSERT(pEle == NULL);
        UT_ASSERT(peaQueueEmpty(pUtQue) == true);
    }
}

UtCase_t gPeaQueueSuit[] = {
    {"peaQueueTest", peaQueueTest},
    {NULL, NULL}
};