#ifndef __PEA_QUEUE_H__
#define __PEA_QUEUE_H__

#include <stdbool.h>

typedef struct PeaQueuePriv PeaQueuePriv_t;

typedef struct PeaQueue {
    void (*pfDestroy)(struct PeaQueue *pQue);
    int (*pfPop)(struct PeaQueue *pQue);
    int (*pfPush)(struct PeaQueue *pQue, void *pEle);
    void *(*pfFront)(struct PeaQueue *pQue);
    void *(*pfRear)(struct PeaQueue *pQue);
    bool (*pfEmpty)(struct PeaQueue *pQue);
    PeaQueuePriv_t *pPriv;
} PeaQueue_t;

PeaQueue_t *peaQueueCreate(int cap, int eleSize);

#endif