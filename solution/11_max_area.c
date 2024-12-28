/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
int maxArea(int* height, int heightSize)
{
    int res = 0;

    if (heightSize < 2) {
       goto l_end;
    }

    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int tmp = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
        if (tmp > res) {
            res = tmp;
        }
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

l_end:
    return res;
}
// @lc code=end

