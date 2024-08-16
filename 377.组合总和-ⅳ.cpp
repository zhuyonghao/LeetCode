/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // 装满背包容量为i有多少种方法
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        // 排列问题与顺序有关先背包再物品
        for (int i = 1; i <= target; i++)
        {
            for (int num : nums)
            {
                // i - num >= 0
                if (i >= num)
                {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end
