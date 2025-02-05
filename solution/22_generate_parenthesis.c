/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Parenthesis {
    char **ppRes;
    int resCap;
    int resNr;
    int resLen;
    char *pStack;
    int stackNr;
} Parenthesis_t;

void parenthesisCreate(Parenthesis_t *pParenthesis, int left, int right)
{
    if (left == 0 && right == 0) {
        pParenthesis->ppRes[pParenthesis->resNr] = (char *)malloc(sizeof(*pParenthesis->ppRes[pParenthesis->resNr])
            * pParenthesis->resLen);
        (void)memcpy(pParenthesis->ppRes[pParenthesis->resNr], pParenthesis->pStack,
            pParenthesis->stackNr * sizeof(*pParenthesis->pStack));
        pParenthesis->ppRes[pParenthesis->resNr][pParenthesis->stackNr] = '\0';
        pParenthesis->resNr++;
        goto l_end;
    }
    if (left > right) {
        goto l_end;
    }
    if (left < 0 || right < 0) {
        goto l_end;
    }

    pParenthesis->pStack[pParenthesis->stackNr++] = '(';
    parenthesisCreate(pParenthesis, left - 1, right);
    pParenthesis->stackNr--;

    pParenthesis->pStack[pParenthesis->stackNr++] = ')';
    parenthesisCreate(pParenthesis, left, right - 1);
    pParenthesis->stackNr--;

l_end:
    return;
}

char** generateParenthesis(int n, int* returnSize)
{
    Parenthesis_t parenthesis;
    parenthesis.resCap = (int)(1u << (2 * n));
    parenthesis.resNr = 0;
    parenthesis.resLen = 2 * n + 1;
    parenthesis.ppRes = (char **)malloc(sizeof(*(parenthesis.ppRes)) * parenthesis.resCap);
    parenthesis.pStack = (char *)malloc(sizeof(*parenthesis.pStack) * parenthesis.resLen);
    parenthesis.stackNr = 0;
    
    parenthesisCreate(&parenthesis, n, n);

    free(parenthesis.pStack);
    *returnSize = parenthesis.resNr;
    return parenthesis.ppRes;
}
// @lc code=end

