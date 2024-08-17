/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        if (n == 0)
            return 0;

        // dp[i][0]: 第i天不持有股票的利润
        // dp[i][1]：第i天持有股票的利润
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            // 第i天不持有股票可能前一天就不持有，也可能前一天持有今天卖了
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);

            // 第i天持有股票可能前一天持有，也可能今天才买
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }

        // 只买卖一次所以卖了股票的钱更多
        return dp[n - 1][0];
    }
};
// @lc code=end
