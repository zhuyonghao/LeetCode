/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        const int MOD = 1000000007;
        int n1 = s.size();
        int n2 = t.size();
        // 以s[i]  t[j]为结尾的个数
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // s中有一个空字符串t
        for (int i = 0; i <= n1; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
                if (s[i - 1] == t[j - 1])
                {
                    // 当前字符匹配到和当前字符没有匹配到
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
                else
                    // 当前字符没有匹配到
                    dp[i][j] = dp[i - 1][j] % MOD;
        }

        return dp[n1][n2];
    }
};
// @lc code=end
