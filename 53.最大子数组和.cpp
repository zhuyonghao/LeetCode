/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         int sum = 0;          // 连续和
//         int result = INT_MIN; // 结果最大值

//         for (int i = 0; i < nums.size(); i++)
//         {
//             // 如果连续和小于0从当前位置出发
//             if (sum < 0)
//                 sum = 0;

//             // 累加
//             sum += nums[i];

//             // 判断是否是最大值进行更新
//             // 如果全是负数可以找到最大值
//             if (result < sum)
//                 result = sum;
//         }
//         return result;
//     }
// };

// DP
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        // 以nums[i]为结尾的子序列和
        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            // 不断更新dp[i]，直至找到以nums[i]为结尾的最大子数组和
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }

        // 找到dp数组中的最大值
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
