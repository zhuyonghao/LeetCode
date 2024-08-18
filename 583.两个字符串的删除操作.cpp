/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
// class Solution
// {
// public:
//     int minDistance(string word1, string word2)
//     {
//         // 找到最大公共长度
//         int n1 = word1.size();
//         int n2 = word2.size();

//         vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

//         for (int i = 1; i <= n1; i++)
//         {
//             for (int j = 1; j <= n2; j++)
//             {
//                 if (word1[i - 1] == word2[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 else
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }

//         return n1 + n2 - 2 * dp[n1][n2];
//     }
// };

class Solution
{
public:
    int minDistance(std::string word1, std::string word2)
    {
        int m = word1.size();
        int n = word2.size();

        // 创建 DP 表
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        // 初始化
        for (int i = 0; i <= m; ++i)
        {
            dp[i][0] = i; // 删除 word1 中的所有字符
        }
        for (int j = 0; j <= n; ++j)
        {
            dp[0][j] = j; // 删除 word2 中的所有字符
        }

        // 填充 DP 表
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1]; // 当前字符相同，无需额外删除
                }
                else
                {
                    dp[i][j] = 1 + std::min(dp[i - 1][j], dp[i][j - 1]); // 删除一个字符后取最小
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end
