#include "pea_queue.h"

typedef struct PeaQueuePriv {
    int cap;
    int nr;
    int eleSize;
    int rear;
    int front;
    void *pBuf;
} PeaQueuePriv_t;

static int peaQueuePopFront(PeaQueue_t *pQue)
{
    int rc = 0;
    if (pQue->pPriv->front == -1) {
        rc = -1;
        goto l_end;
    } else if (pQue->pPriv->front == pQue->pPriv->rear) {
        pQue->pPriv->front = -1;
        pQue->pPriv->rear = -1;
    } else {
        pQue->pPriv->front = (pQue->pPriv->front == pQue->pPriv->cap - 1) ? 0 : pQue->pPriv->front + 1;
    }
    pQue->pPriv->nr--;

l_end:
    return rc;
}

static int peaQueuePushRear(PeaQueue_t *pQue, void *pEle)
{
    int rc = 0;
    if (pQue->pPriv->rear == -1) {
        pQue->pPriv->rear = 0;
        pQue->pPriv->front = 0;
    } else {
        int nextRear = (pQue->pPriv->rear == pQue->pPriv->cap - 1) ? 0 : pQue->pPriv->rear + 1;
        if (nextRear == pQue->pPriv->front) {
            rc = -1;
            goto l_end;
        } else {
            pQue->pPriv->rear = nextRear;
        }
    }
    (void)memcpy(pQue->pPriv->pBuf + pQue->pPriv->rear * pQue->pPriv->eleSize, pEle, pQue->pPriv->eleSize);
    pQue->pPriv->nr++;

l_end:
    return rc;
}

static void *peaQueueFront(PeaQueue_t *pQue)
{
    void *pRes = NULL;
    if (pQue->pPriv->front == -1) {
        goto l_end;
    } else {
        pRes = pQue->pPriv->pBuf + pQue->pPriv->front * pQue->pPriv->eleSize;
    }

l_end:
    return pRes;
}

static void *peaQueueRear(PeaQueue_t *pQue)
{
    void *pRes = NULL;
    if (pQue->pPriv->rear == -1) {
        goto l_end;
    } else {
        pRes = pQue->pPriv->pBuf + pQue->pPriv->rear * pQue->pPriv->eleSize;
    }

l_end:
    return pRes;
}

static bool peaQueueEmpty(PeaQueue_t *pQue)
{
    return pQue->pPriv->front == -1;
}

static int peaQueueNr(PeaQueue_t *pQue)
{
    return pQue->pPriv->nr;
}

static int peaQueueCap(PeaQueue_t *pQue)
{
    return pQue->pPriv->cap;
}

static void peaQueueDestroy(PeaQueue_t *pQue)
{
    if (pQue != NULL) {
        if (pQue->pPriv != NULL) {
            free(pQue->pPriv);
        }
        free(pQue);
    }
    return;
}

PeaQueue_t *peaQueueCreate(int cap, int eleSize)
{
    PeaQueue_t *pQue = (PeaQueue_t *)malloc(sizeof(*pQue));
    if (pQue == NULL) {
        printf("Que malloc failed\n");
        goto l_fail;
    }
    pQue->pPriv = (PeaQueuePriv_t *)malloc(sizeof(*pQue->pPriv) + cap * eleSize);
    if (pQue->pPriv == NULL) {
        printf("Que priv malloc failed\n");
        goto l_fail;
    }
    pQue->pPriv->cap = cap;
    pQue->pPriv->nr = 0;
    pQue->pPriv->eleSize = eleSize;
    pQue->pPriv->front = -1;
    pQue->pPriv->rear = -1;
    pQue->pPriv->pBuf = ((char *)pQue->pPriv) + sizeof(*pQue->pPriv);

    pQue->pfDestroy = peaQueueDestroy;
    pQue->pfPopFront = peaQueuePopFront;
    pQue->pfPushRear = peaQueuePushRear;
    pQue->pfFront = peaQueueFront;
    pQue->pfRear = peaQueueRear;
    pQue->pfEmpty = peaQueueEmpty;
    pQue->pfNr = peaQueueNr;
    pQue->pfCap = peaQueueCap;
    goto l_end;

l_fail:
    peaQueueDestroy(pQue);

l_end:
    return pQue;
}