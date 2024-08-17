/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();

        if (n == 0)
            return 0;
        // dp[i][0]不持有股票，dp[i][1]持有股票
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0] - fee;

        for (int i = 1; i < n; i++)
        {
            // 不持有股票可能保持状态，状态转移(现在买入)
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 持有股票可能保持状态，状态转移(现在卖出)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
        }

        // 最后卖出利润大
        return dp[n - 1][0];
    }
};
// @lc code=end
