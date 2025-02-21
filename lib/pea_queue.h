#ifndef __PEA_QUEUE_H__
#define __PEA_QUEUE_H__

typedef struct PeaQueuePriv PeaQueuePriv_t;

typedef struct PeaQueue {
    void (*pfDestroy)(struct PeaQueue *pQue);
    int (*pfPopFront)(struct PeaQueue *pQue);
    int (*pfPushRear)(struct PeaQueue *pQue, void *pEle);
    void *(*pfFront)(struct PeaQueue *pQue);
    void *(*pfRear)(struct PeaQueue *pQue);
    bool (*pfEmpty)(struct PeaQueue *pQue);
    int (*pfNr)(struct PeaQueue *pQue);
    int (*pfCap)(struct PeaQueue *pQue);
    PeaQueuePriv_t *pPriv;
} PeaQueue_t;

PeaQueue_t *peaQueueCreate(int cap, int eleSize);

#endif