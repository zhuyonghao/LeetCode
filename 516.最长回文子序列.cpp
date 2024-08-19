/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        // i到j最长回文子序列的长度
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // 当前元素到当前元素的长度为1
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        // 遍历顺序由递推顺序得来
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
