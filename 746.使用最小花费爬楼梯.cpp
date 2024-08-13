/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // 到达i层的最小花费
        vector<int> dp(cost.size() + 1);

        // 初始化
        // 到达0，1不消耗体力，只有跳的时候消耗
        dp[0] = 0;
        dp[1] = 0;

        // 需要跳到超出cost最大下标
        for (int i = 2; i <= cost.size(); i++)
        {
            // 从i-1开始跳需要的花费和从i-2开始跳所需要的花费哪一个小
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[cost.size()];
    }
};
// @lc code=end
