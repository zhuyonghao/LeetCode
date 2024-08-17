/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 三种状态
        int hold = 0;
        int sold = 1;
        int rest = 2;
        int n = prices.size();

        if (n == 0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(3, 0));

        dp[0][hold] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            // 持有股票的状态可能保持前面的状态，也可能从rest状态转移
            dp[i][hold] = max(dp[i - 1][hold], dp[i - 1][rest] - prices[i]);
            // 卖出股票的状态只能由前面买入状态转移，因为冷冻期不可能维持卖出状态
            dp[i][sold] = dp[i - 1][hold] + prices[i];
            // rest状态可能保持前面的状态，也可能从sold状态转移,利润不变
            dp[i][rest] = max(dp[i - 1][rest], dp[i - 1][sold]);
        }

        // 卖出的状态值和不买入
        return max(dp[n - 1][sold], dp[n - 1][rest]);
    }
};
// @lc code=end
