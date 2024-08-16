/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 检查边界条件
        if (sum < abs(target) || (sum + target) % 2 != 0)
        {
            return 0;
        }

        int newTarget = (sum + target) / 2;

        // 如果newTarget非常大，避免分配过多内存
        if (newTarget < 0)
        {
            return 0;
        }

        // 动态规划数组初始化
        vector<int> dp(newTarget + 1, 0);
        dp[0] = 1; // 和为0的方法只有1种，就是不选择任何元素

        // 0/1背包问题的经典处理过程
        for (int num : nums)
        {
            // 逆序更新
            for (int j = newTarget; j >= num; j--)
            {
                dp[j] += dp[j - num];
            }
        }

        return dp[newTarget];
    }
};
// @lc code=end
