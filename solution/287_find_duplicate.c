/*
 * @lc app=leetcode.cn id=287 lang=c
 *
 * [287] 寻找重复数
 */

// @lc code=start

static bool isInHalf(int *nums, int numsSize, int target)
{
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= target) {
            cnt++;
        }
    }
    return cnt > target;
}

int findDuplicate(int* nums, int numsSize)
{
    int left = 1;
    int right = numsSize - 1;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;

        if (isInHalf(nums, numsSize, mid) != false) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
// @lc code=end

