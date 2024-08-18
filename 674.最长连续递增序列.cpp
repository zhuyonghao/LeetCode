/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int n = nums.size();
        // 以nums[i]为结尾的长度
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
                dp[i] = dp[i - 1] + 1;
        }

        int maxLength = 1;

        for (int length : dp)
            maxLength = max(maxLength, length);

        return maxLength;
    }
};
// @lc code=end
