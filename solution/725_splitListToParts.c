/*
 * @lc app=leetcode.cn id=725 lang=c
 *
 * [725] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize)
{
    struct ListNode **ppRes = (struct ListNode **)malloc((k + 1) * sizeof(struct ListNode *));
    struct ListNode **ppPre = (struct ListNode **)malloc((k + 1) * sizeof(struct ListNode *));
    for (int i = 0; i < (k + 1); i++) {
        ppRes[i] = head;
        ppPre[i] = NULL;
    }
    int resNr = k;
    while (ppRes[k] != NULL) {
        for (int i = 1; i < k + 1; i++) {
            for (int j = i; j < k + 1; j++) {
                if (ppRes[j] != NULL) {
                    ppPre[j] = ppRes[j];
                    ppRes[j] = ppRes[j]->next;
                }
            }
            if (ppRes[k] == NULL) {
                break;
            }
        }
    }

    for (int i = 1; i < k + 1; i++) {
        if (ppPre[i] != NULL) {
            ppPre[i]->next = NULL;
        }
    }

    *returnSize = resNr;
    return ppRes;
}
// @lc code=end

