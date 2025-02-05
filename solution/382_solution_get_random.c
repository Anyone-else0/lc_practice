/*
 * @lc app=leetcode.cn id=382 lang=c
 *
 * [382] 链表随机节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX_STEP (100)

typedef struct Solution_s
{
    struct ListNode *pList;
    struct ListNode *pCurNode;
} Solution;


Solution* solutionCreate(struct ListNode* head)
{
    Solution *pSlt = (Solution *)malloc(sizeof(Solution));
    pSlt->pList = head;
    pSlt->pCurNode = head;

    return pSlt;
}

int solutionGetRandom(Solution* obj)
{
    int step = rand() % MAX_STEP;

    for (int i = 0; i <= step; i++) {
        if (obj->pCurNode->next != NULL) {
            obj->pCurNode = obj->pCurNode->next;
        } else {
            obj->pCurNode = obj->pList;
        }
    }

    return obj->pCurNode->val;
}

void solutionFree(Solution* obj)
{
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
// @lc code=end

