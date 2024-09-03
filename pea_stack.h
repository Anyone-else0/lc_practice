#ifndef __PEA_STACK_H__
#define __PEA_STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PEA_STACK_TYPEDEF(__stackTypeName, __cap, __type)                                                           \
    typedef struct __stackTypeName##_tag {                                                                          \
        int cap;                                                                                                    \
        int nr;                                                                                                     \
        __type buf[(__cap)];                                                                                        \
    } __stackTypeName;

#define PEA_STACK_DEF(__stackTypeName, __name)                                                                      \
    __stackTypeName __name = {                                                                                      \
        .cap = sizeof(__name.buf) / sizeof(__name.buf[0]),                                                          \
        .nr = 0,                                                                                                    \
        .buf = {0}};                                                                                                \

#define PEA_STACK_CREATE(__stackTypeName, __cap) ({                                                                 \
    __stackTypeName *__pStack = (__stackTypeName *)malloc(sizeof(*__pStack) + sizeof(*__pStack->buf) * __cap);      \
    if (__pStack == NULL) {                                                                                         \
        printf("Stack malloc failed.");                                                                             \
    } else {                                                                                                        \
        __pStack->cap = (__cap);                                                                                    \
        __pStack->nr = 0;                                                                                           \
    }                                                                                                               \
    __pStack;})

#define PEA_STACK_TOP(__pStack) ({                                                                                  \
    typeof((__pStack)->buf[0]) *__pEle;                                                                             \
    if ((__pStack)->nr == 0) {                                                                                      \
        __pEle = NULL;                                                                                              \
    } else {                                                                                                        \
        __pEle = &(__pStack)->buf[(__pStack)->nr - 1];                                                              \
    }                                                                                                               \
    __pEle;})

#define PEA_STACK_PUSH(__pStack, __ele) ({                                                                          \
    int __rc;                                                                                                       \
    if ((__pStack)->nr == (__pStack)->cap) {                                                                        \
        __rc = -1;                                                                                                  \
    } else {                                                                                                        \
        __rc = 0;                                                                                                   \
        (__pStack)->buf[(__pStack)->nr] = (__ele);                                                                  \
        (__pStack)->nr++;                                                                                           \
    }                                                                                                               \
    __rc;})

#define PEA_STACK_POP(__pStack) ({                                                                                  \
    int __rc;                                                                                                       \
    if ((__pStack)->nr == 0) {                                                                                      \
        __rc = -1;                                                                                                  \
    } else {                                                                                                        \
        __rc = 0;                                                                                                   \
        (__pStack)->nr--;                                                                                           \
    }                                                                                                               \
    __rc;})

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