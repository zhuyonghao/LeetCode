/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
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

        // dp[i][0]不操作
        // dp[i][1]第一次买入
        // dp[i][2]第一次卖出
        // dp[i][3]第二次买入
        // dp[i][4]第二次卖出
        vector<vector<int>> dp(n, vector<int>(5, 0));

        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            // 第i次不操作等于前一次不操作
            dp[i][0] = dp[i - 1][0];
            // 第i次第一次买入可能前一次买入，这一次买入
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            // 第i次第一次卖出可能前一次卖出，这一次卖出
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            // 第i次第二次买入可能前一次买入，这一次买入
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            // 第i次第二次卖出可能前一次卖出，这一次卖出
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        // 返回第一次卖出和第二次卖出的最大值
        // 也可以直接返回第二次卖出，第一次卖出相当于第一次卖出这次买入再卖出
        return max(dp[n - 1][2], dp[n - 1][4]);
    }
};
// @lc code=end
