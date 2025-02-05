/*
 * @lc app=leetcode.cn id=214 lang=c
 *
 * [214] 最短回文串
 */

// @lc code=start

bool isPalindrome(char *s, int len)
{
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            return false;
        }
    }
    return true;
}

char* shortestPalindrome(char* s)
{
    int sLen = strlen(s);

    if (sLen == 0) {
        return s;
    }

    int childLen;
    for (childLen = sLen; childLen > 0; childLen--) {
        if (isPalindrome(s, childLen)) {
            break;
        }
    }
    char *pRes = NULL;
    if (childLen == sLen) {
        pRes = strdup(s);
        goto l_end;
    } else {
        pRes = (char *)malloc(sizeof(*pRes) * (sLen + sLen - childLen + 1));
        int resIdx = 0;
        for (resIdx = 0; resIdx < sLen - childLen; resIdx++) {
            pRes[resIdx] = s[sLen - resIdx - 1];
        }
        memcpy(&pRes[resIdx], s, sLen);
        pRes[sLen + sLen - childLen] = '\0';
        goto l_end;
    }

l_end:
    return pRes;
}
// @lc code=end

