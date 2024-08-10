/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;          // 连续和
        int result = INT_MIN; // 结果最大值

        for (int i = 0; i < nums.size(); i++)
        {
            // 如果连续和小于0从当前位置出发
            if (sum < 0)
                sum = 0;

            // 累加
            sum += nums[i];

            // 判断是否是最大值进行更新
            // 如果全是负数可以找到最大值
            if (result < sum)
                result = sum;
        }
        return result;
    }
};
// @lc code=end
