#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pea_queue.h"

PeaQueue_t *peaQueueCreate(int cap, int eleSize)
{
    PeaQueue_t *pQue = (PeaQueue_t *)malloc(sizeof(*pQue) + cap * eleSize);
    if (pQue == NULL) {
        printf("Que malloc failed\n");
        goto l_end;
    }
    pQue->cap = cap;
    pQue->eleSize = eleSize;
    pQue->front = -1;
    pQue->rear = -1;
    pQue->pBuf = pQue->buf;

l_end:
    return pQue;
}

void peaQueueDestroy(PeaQueue_t *pQue)
{
    free(pQue);
    return;
}

int peaQueuePop(PeaQueue_t *pQue)
{
    int rc = 0;
    if (pQue->front == -1) {
        rc = -1;
        goto l_end;
    } else if (pQue->front == pQue->rear) {
        pQue->front = -1;
        pQue->rear = -1;
    } else {
        pQue->front = (pQue->front == pQue->cap) ? 0 : pQue->front + 1;
    }

l_end:
    return rc;
}

int peaQueuePush(PeaQueue_t *pQue, void *pEle)
{
    int rc = 0;
    if (pQue->rear == -1) {
        pQue->rear = 0;
        pQue->front = 0;
    } else {
        int nextRear = (pQue->rear == pQue->cap - 1) ? 0 : pQue->rear + 1;
        if (nextRear == pQue->front) {
            rc = -1;
            goto l_end;
        } else {
            pQue->rear = nextRear;
        }
    }
    (void)memcpy(pQue->pBuf + pQue->rear * pQue->eleSize, pEle, pQue->eleSize);

l_end:
    return rc;
}

void *peaQueueFront(PeaQueue_t *pQue)
{
    void *pRes = NULL;
    if (pQue->front == -1) {
        goto l_end;
    } else {
        pRes = pQue->pBuf + pQue->front * pQue->eleSize;
    }

l_end:
    return pRes;
}

void *peaQueueRear(PeaQueue_t *pQue)
{
    void *pRes = NULL;
    if (pQue->rear == -1) {
        goto l_end;
    } else {
        pRes = pQue->pBuf + pQue->rear * pQue->eleSize;
    }

l_end:
    return pRes;
}

bool peaQueueEmpty(PeaQueue_t *pQue)
{
    return pQue->front == -1;
}