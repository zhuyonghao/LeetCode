/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // 到达m,n有多少种方案
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // // 将最上面一行和最左边一列初始化唯一，因为到达方案只有一种
        // // 最左边一列
        // for (int i = 0; i < m; i++)
        //     dp[i][0] = 1;
        // // 最上面一行
        // for (int j = 0; j < n; j++)
        //     dp[0][j] = 1;

        // 遍历顺序为递推顺序从左往右从上往下
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                // 从左边往右边的方法加上从上面网下面的方法
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end
