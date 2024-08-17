/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
// 贪心
// class Solution
// {
// public:
//     // 只需要买卖所有正坡就可以获得最大利润
//     int maxProfit(vector<int> &prices)
//     {
//         int sum = 0;

//         if (prices.size() < 2)
//             return sum;

//         for (int i = 1; i < prices.size(); i++)
//         {
//             // 如果差为正数则累加
//             if (prices[i] - prices[i - 1] > 0)
//                 sum += prices[i] - prices[i - 1];
//         }

//         return sum;
//     }
// };

// 动态规划
class Solution
{
public:
    // 只需要买卖所有正坡就可以获得最大利润
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        if (n == 0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            // 第i天不持有股票可能前一天不持有，可能今天卖出
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 因为多次买卖
            // 第i天持有，可能前一天持有，也可能今天买入
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        // 最后一天卖了利润最多
        return dp[n - 1][0];
    }
};
// @lc code=end
