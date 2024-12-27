#ifndef __155_MIN_STACK_H__
#define __155_MIN_STACK_H__

typedef struct {
    
} MinStack;

MinStack* minStackCreate();
void minStackPush(MinStack* obj, int val);
void minStackPop(MinStack* obj);
int minStackTop(MinStack* obj);
int minStackGetMin(MinStack* obj);
void minStackFree(MinStack* obj);

#endif