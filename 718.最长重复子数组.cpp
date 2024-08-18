/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // 以n1为结尾n2为结尾最长重复子数组
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // 将长度初始化为0
        int maxLength = 0;

        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }

        return maxLength;
    }
};
// @lc code=end
