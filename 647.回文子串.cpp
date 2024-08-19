/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        // i到j的是否有回文子串
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int result = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    // 如果只有一个或者只有两个字串
                    if (j - i <= 1)
                    {
                        dp[i][j] = true;
                        result++;
                    }
                    // 两个以上
                    else if (dp[i + 1][j - 1] == true)
                    {
                        // 缩短范围
                        dp[i][j] = true;
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
