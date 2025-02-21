#ifndef __PEA_STACK_H__
#define __PEA_STACK_H__

typedef struct PeaStackPriv PeaStackPriv_t;

typedef struct PeaStack {
    void (*pfDestroy)(struct PeaStack *pStack);
    int (*pfPop)(struct PeaStack *pStack);
    int (*pfPush)(struct PeaStack *pStack, void *pEle);
    void *(*pfTop)(struct PeaStack *pStack);
    bool (*pfEmpty)(struct PeaStack *pStack);
    int (*pfNr)(struct PeaStack *pStack);
    int (*pfCap)(struct PeaStack *pStack);
    PeaStackPriv_t *pPriv;
} PeaStack_t;

PeaStack_t *peaStackCreate(int cap, int eleSize);

#endif