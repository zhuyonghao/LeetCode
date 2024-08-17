/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();

        if (n == 0)
            return 0;

        // 一共有2k+1种状态
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));

        // 将奇数买入初始化
        for (int j = 0; j < 2 * k + 1; j++)
        {
            if (j % 2 == 1)
                dp[0][j] = -prices[0];
        }

        for (int i = 1; i < n; i++)
            for (int j = 0; j < 2 * k + 1; j++)
            {
                // 如果为奇数则买入可能前一次已经买入，当前次买入
                if (j % 2 == 1)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                }
                // 如果为偶数则卖出可能前一次已经卖出，当前次卖出
                else if (j % 2 == 0 && j != 0)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                }
            }

        // 返回最后一次卖出
        return dp[n - 1][2 * k];
    }
};
// @lc code=end
