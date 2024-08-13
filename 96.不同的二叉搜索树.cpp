/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        // 对于n二叉搜索树的个数
        vector<int> dp(n + 1, 0);
        // 二叉树为空有一种排列
        dp[0] = 1;
        // 有一个节点有一种排列方式
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            // j为根节点
            // 1 2 3 ...i为根节点
            for (int j = 1; j <= i; j++)
            {
                // 左边种类乘上右边种类
                // 将所有树作为根节点累加
                dp[i] += dp[j - 1] * dp[i - j];
            }

        return dp[n];
    }
};
// @lc code=end
