/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (const string &str : strs)
        {
            int zero_count = count(str.begin(), str.end(), '0');
            int one_count = str.size() - zero_count;

            // 倒序遍历，避免覆盖掉尚未计算的状态
            for (int i = m; i >= zero_count; --i)
            {
                for (int j = n; j >= one_count; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zero_count][j - one_count] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end
