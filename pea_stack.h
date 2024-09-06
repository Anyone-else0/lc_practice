#ifndef __PEA_STACK_H__
#define __PEA_STACK_H__

#include <stdbool.h>

typedef struct PeaStack {
    int cap;
    int nr;
    int eleSize;
    void *pBuf;
} PeaStack_t;

int peaStackPop(PeaStack_t *pStack);
int peaStackPush(PeaStack_t *pStack, void *pEle);
void *peaStackTop(PeaStack_t *pStack);
bool peaStackEmpty(PeaStack_t *pStack);
PeaStack_t *peaStackCreate(int cap, int eleSize);
void peaStackDestroy(PeaStack_t *pStack);

#endif