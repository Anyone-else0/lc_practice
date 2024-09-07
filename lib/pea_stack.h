#ifndef __PEA_STACK_H__
#define __PEA_STACK_H__

#include <stdbool.h>

typedef struct PeaStack {
    int cap;
    int nr;
    int eleSize;
    void *pBuf;
    void (*pfDestroy)(struct PeaStack *pStack);
    int (*pfPop)(struct PeaStack *pStack);
    int (*pfPush)(struct PeaStack *pStack, void *pEle);
    void *(*pfTop)(struct PeaStack *pStack);
    bool (*pfEmpty)(struct PeaStack *pStack);
} PeaStack_t;

PeaStack_t *peaStackCreate(int cap, int eleSize);

#endif