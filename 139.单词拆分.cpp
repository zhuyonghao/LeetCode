/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // 便于查找
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // 长度为i能否被包含
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        // 排列数先背包再物品
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // 0--j被包含并且j--i被包含所以0--i包含
                if (dp[j] && dict.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end
