/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
public:
    // int fib(int n)
    // {
    //     if (n == 1)
    //         return 1;
    //     if (n == 2)
    //         return 1;
    //     if (n > 2)
    //         return fib(n - 1) + fib(n - 2);
    //     return 0;
    // }
    // int fib(int n)
    // {
    //     // 1. 确定dp数组含义
    //     // 用来存放n个数从1开始
    //     // 每个下标所对应的数组值为斐波那契数
    //     vector<int> dp(n + 1, 1);

    //     // 3. dp数组初始化
    //     dp[0] = 0;

    //     // 4. 遍历顺序从前往后递推
    //     for (int i = 3; i <= n; i++)
    //         // 2. 递推公式
    //         dp[i] = dp[i - 1] + dp[i - 2];

    //     // 返回第n个元素
    //     return dp[n];

    //     // 5. 打印数组
    // }

    // 只依赖三个变量进行状态压缩
    int fib(int n)
    {
        if (n == 0)
            return 0;

        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        int sum = 0;

        for (int i = 2; i <= n; i++)
        {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }

        return dp[1];
    }
};
// @lc code=end
