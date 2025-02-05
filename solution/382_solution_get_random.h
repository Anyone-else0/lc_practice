#ifndef __382_SOLUTION_GET_RANDOM_H__
#define __382_SOLUTION_GET_RANDOM_H__

#include "pea_type.h"

typedef struct Solution_s Solution;

Solution* solutionCreate(struct ListNode* head);

int solutionGetRandom(Solution* obj);

void solutionFree(Solution* obj);

#endif