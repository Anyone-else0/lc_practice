/*
 * @lc app=leetcode.cn id=155 lang=c
 *
 * [155] 最小栈
 */

// @lc code=start
#include "stdlib.h"
#define STACK_SIZE (30000)
typedef struct {
    long long int data[STACK_SIZE];
    int top;
    long long int min;
} MinStack;

MinStack* minStackCreate()
{
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->top = -1;
    obj->min = 0;
    return obj;
}

void minStackPush(MinStack* obj, int val)
{
    if (obj->top >= STACK_SIZE -1) {
        goto l_end;
    }

    if (obj->top < 0) {
        obj->min = val;
    }

    obj->top++;
    obj->data[obj->top] = val - obj->min;
    obj->min = obj->min < val ? obj->min : val;

l_end:
    return;
}

void minStackPop(MinStack* obj)
{
    if (obj->top < 0) {
        goto l_end;
    }

    if (obj->data[obj->top] < 0) {
        obj->min = obj->min - obj->data[obj->top];
    }

    obj->top--;

l_end:
    return;
}

int minStackTop(MinStack* obj)
{
    int ret = 0;
    if (obj->top < 0) {
        goto l_end;
    }

    if (obj->data[obj->top] < 0) {
        ret = obj->min;
    } else {
        ret = obj->data[obj->top] + obj->min;
    }

l_end:
    return ret;
}

int minStackGetMin(MinStack* obj)
{
    return obj->min;
}

void minStackFree(MinStack* obj)
{
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
// @lc code=end

