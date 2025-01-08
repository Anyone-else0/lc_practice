/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s)
{
    char *pRes;
    int sLen = strlen(s);
    if (sLen <= 1) {
        pRes = strdup(s);
        goto l_end;
    }

    int left;
    int right;
    int maxLen = 1;
    int maxBegin = 0;
    for (int i = 0; i < sLen; i++) {
        left = i;
        right = i + 1;
        while (left >= 0 && right <= sLen - 1) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }

        if (right - left - 1 > maxLen) {
            maxBegin = left + 1;
            maxLen = right - left - 1;
        }

        left = i;
        right = i + 2;
        while (left >= 0 && right <= sLen - 1) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }

        if (right - left - 1 > maxLen) {
            maxBegin = left + 1;
            maxLen = right - left - 1;
        }
    }

    pRes = (char *)malloc(sizeof(*pRes) * (maxLen + 1));
    (void)memcpy(pRes, &s[maxBegin], maxLen * sizeof(*pRes));
    pRes[maxLen] = '\0';

l_end:
    return pRes;
}
// @lc code=end

