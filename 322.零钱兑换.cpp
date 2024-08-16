/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // 装满容量为i的背包有多少种方法
        // 每次取最小值需要初始化为最大值
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        // 既可以先遍历背包也可以先遍历物品
        // 因为该题与顺序无关只需要个数
        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (i >= coin && dp[i - coin] != INT_MAX)
                {
                    // 每次更新取最小值
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        // 如果为最大值则无方案，反之则输出
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end
