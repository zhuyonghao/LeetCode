/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // 以nums[i]为结尾的递增子序列
        vector<int> dp(n, 1);

        // 每次以nums[i]结尾的最大长度
        int maxLength = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    // 不断更新dp[i]最大值
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            // 更新最大长度
            maxLength = max(dp[i], maxLength);
        }

        return maxLength;
    }
};
// @lc code=end
