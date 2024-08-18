/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        // 操作word1使其变为word2
        int n1 = word1.size();
        int n2 = word2.size();
        // 操作到word1[i] word2[j]所需要的次数
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // 将word1转化为空字符
        // 删除
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = i;
        }
        // 将将空字符转化为word2
        // 添加
        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = j;
        }

        // 将字符串word1删成word2
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    // 不修改
                    dp[i][j] = dp[i - 1][j - 1];
                // 修改
                else
                    dp[i][j] = 1 + min({
                                       dp[i - 1][j],    // 插入
                                       dp[i][j - 1],    // 删除
                                       dp[i - 1][j - 1] // 替换
                                   });
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end
