/*
 * @lc app=leetcode.cn id=698 lang=c
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct SubSetsInfo {
    int *nums;
    int numsSize;
    int k;

    int bucketTgt;
    unsigned int curUsedMap;

    int bucketSum[16];
} SubSetsInfo_t;

static bool canPartition(SubSetsInfo_t *pInfo, int curBucketIdx, int startNumsIdx)
{
    if (curBucketIdx >= pInfo->k) {
        return true;
    }

    for (int i = startNumsIdx; i < pInfo->numsSize; i++) {
        if ((pInfo->curUsedMap & (1 << i)) != 0 ||
            pInfo->bucketSum[curBucketIdx] + pInfo->nums[i] > pInfo->bucketTgt) {
            continue;
        }

        pInfo->bucketSum[curBucketIdx] += pInfo->nums[i];
        pInfo->curUsedMap |= (1 << i);

        int nextBucketIdx = curBucketIdx;
        int nextNumsIdx = i + 1;

        if (pInfo->bucketSum[curBucketIdx] == pInfo->bucketTgt) {
            nextBucketIdx++;
            nextNumsIdx = 0;
        }
        bool rc = canPartition(pInfo, nextBucketIdx, nextNumsIdx);
        if (rc != false) {
            return true;
        } else {
            pInfo->bucketSum[curBucketIdx] -= pInfo->nums[i];
            pInfo->curUsedMap &= ~(1 << i);
        }
        if (pInfo->bucketSum[curBucketIdx] == 0) {
            break;
        }
    }

    return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k)
{
    bool rc = false;
    int numsSum = 0;
    for (int i = 0; i < numsSize; i++) {
        numsSum += nums[i];
    }
    if (numsSum % k != 0) {
        goto l_end;
    }

    SubSetsInfo_t info;
    info.nums = nums;
    info.numsSize = numsSize;
    info.k = k;

    info.bucketTgt = numsSum / k;
    info.curUsedMap = 0;

    (void)memset(info.bucketSum, 0, sizeof(info.bucketSum));

    rc = canPartition(&info, 0, 0);

l_end:
    return rc;
}
// @lc code=end

