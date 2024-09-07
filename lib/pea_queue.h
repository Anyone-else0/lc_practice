#ifndef __PEA_QUEUE_H__
#define __PEA_QUEUE_H__

#include <stdbool.h>

typedef struct PeaQueue {
    int cap;
    int eleSize;
    int rear;
    int front;
    void *pBuf;
    void (*pfDestroy)(struct PeaQueue *pQue);
    int (*pfPop)(struct PeaQueue *pQue);
    int (*pfPush)(struct PeaQueue *pQue, void *pEle);
    void *(*pfFront)(struct PeaQueue *pQue);
    void *(*pfRear)(struct PeaQueue *pQue);
    bool (*pfEmpty)(struct PeaQueue *pQue);
} PeaQueue_t;

PeaQueue_t *peaQueueCreate(int cap, int eleSize);

#endif