/*
 * @lc app=leetcode.cn id=816 lang=c
 *
 * [816] 模糊坐标
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_RET_SIZE (1500)
#define MAX_WORD_SIZE (20)

static bool isValid(char *s, int sLen, int dotPos)
{
    if (sLen == 1) {
        return true;
    }

    if (dotPos == -1) {
        if (s[0] == '0') {
            return false;
        }
        return true;
    }

    if (dotPos > 0 && s[0] == '0') {
        return false;
    }
    if (dotPos < sLen - 1 && s[sLen - 1] == '0') {
        return false;
    }

    return true;
}

char *resGen(char *pLeft, int leftDotPos, char *pRight, int rightDotPos)
{
    char *pRes = (char *)malloc(MAX_WORD_SIZE * 2 + 3);
    if (pRes == NULL) {
        return NULL;
    }

    int pos = 0;
    pRes[pos++] = '(';

    if (leftDotPos == -1) {
        memcpy(pRes + pos, pLeft, strlen(pLeft));
        pos += strlen(pLeft);
    } else {
        memcpy(pRes + pos, pLeft, leftDotPos + 1);
        pos += leftDotPos + 1;
        pRes[pos++] = '.';
        memcpy(pRes + pos, pLeft + leftDotPos + 1, strlen(pLeft) - leftDotPos - 1);
        pos += strlen(pLeft) - leftDotPos - 1;
    }

    pRes[pos++] = ',';
    pRes[pos++] = ' ';

    if (rightDotPos == -1) {
        memcpy(pRes + pos, pRight, strlen(pRight));
        pos += strlen(pRight);
    } else {
        memcpy(pRes + pos, pRight, rightDotPos + 1);
        pos += rightDotPos + 1;
        pRes[pos++] = '.';
        memcpy(pRes + pos, pRight + rightDotPos + 1, strlen(pRight) - rightDotPos - 1);
        pos += strlen(pRight) - rightDotPos - 1;
    }

    pRes[pos++] = ')';
    pRes[pos] = '\0';

    return pRes;
}

char** ambiguousCoordinates(char* s, int* returnSize)
{
    char **ppRes = (char **)malloc(sizeof(char *) * MAX_RET_SIZE);
    *returnSize = 0;

    char left[MAX_WORD_SIZE];
    char right[MAX_WORD_SIZE];

    int len = strlen(s);

    for (int i = 2; i < len - 1; i++) {
        (void)memcpy(left, s + 1, i - 1);
        left[i - 1] = '\0';
        (void)memcpy(right, s + i, len - i - 1);
        right[len - i - 1] = '\0';
        for (int j = -1; j < i - 2; j++) {
            if (isValid(left, i - 1, j)) {
                for (int k = -1; k < len - i - 2; k++) {
                    if (isValid(right, len - i - 1, k)) {
                        ppRes[*returnSize] = resGen(left, j, right, k);
                        (*returnSize)++;
                    }
                }
            }
        }
    }
    return ppRes;
}
// @lc code=end

