/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
// class Solution
// {
// public:
//     int lastStoneWeightII(vector<int> &stones)
//     {
//         int sum = accumulate(stones.begin(), stones.end(), 0);
//         int target = sum / 2;
//         vector<bool> dp(target + 1, false);
//         dp[0] = true;

//         for (int stone : stones)
//         {
//             for (int j = target; j >= stone; --j)
//             {
//                 dp[j] = dp[j] || dp[j - stone];
//             }
//         }

//         for (int j = target; j >= 0; --j)
//         {
//             if (dp[j])
//             {
//                 return sum - 2 * j;
//             }
//         }

//         return 0;
//     }
// };

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        vector<int> dp(15001, 0);
        int sum = 0;
        for (int i = 0; i < stones.size(); i++)
            sum += stones[i];
        int target = sum / 2;
        for (int i = 0; i < stones.size(); i++)
        { // 遍历物品
            for (int j = target; j >= stones[i]; j--)
            { // 遍历背包
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};

// @lc code=end
