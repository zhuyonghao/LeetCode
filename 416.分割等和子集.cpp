/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
// class Solution
// {
// public:
//     bool canPartition(vector<int> &nums)
//     {
//         // 如果和为奇数则不可分割
//         int sum = accumulate(nums.begin(), nums.end(), 0);

//         // 如果总和为奇数，则无法分割成两个和相等的子集
//         if (sum % 2 != 0)
//         {
//             return false;
//         }

//         int target = sum / 2;
//         vector<bool> dp(target + 1, false);
//         dp[0] = true;

//         for (int num : nums)
//             for (int j = target; j >= num; j--)
//                 dp[j] = dp[j] || dp[j - num];

//         return dp[target];
//     }
// };

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;

        // dp[i]中的i表示背包内总和
        // 题目中说：每个数组中的元素不会超过 100，数组的大小不会超过 200
        // 总和不会大于20000，背包最大只需要其中一半，所以10001大小就可以了
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        // 也可以使用库函数一步求和
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;

        // 开始 01背包
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            { // 每一个元素一定是不可重复放入，所以从大到小遍历
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        // 集合中的元素正好可以凑成总和target
        if (dp[target] == target)
            return true;
        return false;
    }
};
// @lc code=end
