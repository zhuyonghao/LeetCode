/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    // int climbStairs(int n)
    // {
    //     // 如果数组只有一个元素对2操作将会导致越界
    //     if (n < 2)
    //         return n;

    //     // dp数组的每个下标所对应的值为到n层有几种方法
    //     vector<int> dp(n + 1);

    //     // 递推公式
    //     // 到达1层 1
    //     // 到达2层 2
    //     // 到达3层 从第二层走一步有2种方法，从第一层走两步有一种方法，所以有三种方法
    //     // 到达n层 从n-1层走一步的方法加上从n-2层走两步的方法

    //     // 初始化
    //     dp[1] = 1;
    //     dp[2] = 2;

    //     // 递推从前往后
    //     for (int i = 3; i <= n; i++)
    //         dp[i] = dp[i - 1] + dp[i - 2];

    //     return dp[n];
    // }

    int climbStairs(int n)
    {
        if (n < 2)
            return n;

        int dp[2];
        dp[0] = 1;
        dp[1] = 2;
        int sum = 0;

        for (int i = 3; i <= n; i++)
        {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }

        return dp[1];
    }
};
// @lc code=end
