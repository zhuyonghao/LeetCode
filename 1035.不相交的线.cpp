/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution
{
public:
    // 求最长相等序列长度
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    // 保持原值
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        return dp[n1][n2];
    }
};
// @lc code=end
