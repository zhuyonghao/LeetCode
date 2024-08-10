/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    // 下标对应的值是可以跳跃的最大长度
    // 能不能跳到末尾元素
    bool canJump(vector<int> &nums)
    {
        int cover = 0; // 覆盖范围

        // 如果长度为1则返回true
        if (nums.size() == 1)
            return true;
        // 在已有覆盖范围内搜索
        for (int i = 0; i <= cover; i++)
        {
            // 比较新范围和旧范围进行更新
            cover = max(cover, i + nums[i]);
            // 如果可以超出最后一位则返回true
            if (cover >= nums.size() - 1)
                return true;
        }
        // 如果没有超出就返回false
        return false;
    }
};
// @lc code=end
