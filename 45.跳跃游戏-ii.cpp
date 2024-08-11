/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;

        int jumps = 0;       // 跳跃次数
        int curEnd = 0;      // 当前跳跃范围的终点
        int curFarthest = 0; // 当前能跳跃到最远的位置

        for (int i = 0; i < nums.size() - 1; i++)
        {
            curFarthest = max(curFarthest, i + nums[i]);

            // 当到达当前跳跃的终点
            if (i == curEnd)
            {
                jumps++;              // 增加跳跃次数
                curEnd = curFarthest; // 更新跳跃范围的终点

                // 如果已经可以到达或超过终点，则停止
                if (curEnd >= nums.size() - 1)
                    break;
            }
        }
        return jumps;
    }
};
// @lc code=end
