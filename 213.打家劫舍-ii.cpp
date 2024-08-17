/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
public:
    int robLinear(vector<int> &nums, int start, int end)
    {
        int n = end - start + 1;
        if (n == 1)
            return nums[start];
        vector<int> dp(n, 0);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }

        return dp[n - 1];
    }

    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];

        int rob1 = robLinear(nums, 0, nums.size() - 2);
        int rob2 = robLinear(nums, 1, nums.size() - 1);

        return max(rob1, rob2);
    }
};
// @lc code=end
