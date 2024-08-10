/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution
{
public:
    // 只需要买卖所有正坡就可以获得最大利润
    int maxProfit(vector<int> &prices)
    {
        int sum = 0;

        if (prices.size() < 2)
            return sum;

        for (int i = 1; i < prices.size(); i++)
        {
            // 如果差为正数则累加
            if (prices[i] - prices[i - 1] > 0)
                sum += prices[i] - prices[i - 1];
        }

        return sum;
    }
};
// @lc code=end
