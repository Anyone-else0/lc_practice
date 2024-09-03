#ifndef __PEA_QUEUE_H__
#define __PEA_QUEUE_H__

#include <stdbool.h>

typedef struct PeaQueue {
    int cap;
    int eleSize;
    int rear;
    int front;
    void *pBuf;
    char buf[0];
} PeaQueue_t;

PeaQueue_t *peaQueueCreate(int cap, int eleSize);
void peaQueueDestroy(PeaQueue_t *pQue);
int peaQueuePop(PeaQueue_t *pQue);
int peaQueuePush(PeaQueue_t *pQue, void *pEle);
void *peaQueueFront(PeaQueue_t *pQue);
void *peaQueueRear(PeaQueue_t *pQue);
bool peaQueueEmpty(PeaQueue_t *pQue);

#endif