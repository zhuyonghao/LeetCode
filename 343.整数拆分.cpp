/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        // 元素i拆分后乘积最大值
        vector<int> dp(n + 1, 0);
        // 2是最小分割数，乘积为1
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
            for (int j = 1; j < i; j++)
            {
                // 不拆，拆分, 多个拆分
                // dp[i]不断更新取最大值
                // j * dp[i - j]包含拆分的左右情况
                // dp[j] * dp[i - j]默认四种
                dp[i] = max({j * (i - j), j * dp[i - j], dp[i]});
            }

        return dp[n];
    }
};
// @lc code=end
