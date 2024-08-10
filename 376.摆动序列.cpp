/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        // 如果长度为0和1直接返回
        if (nums.size() < 2)
            return nums.size();

        int preDiff = 0; // 前坡
        int curDiff = 0; // 后坡
        int result = 1;  // 如果长度为2将结果初始为1

        // 遍历每一个元素除了最后一个
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curDiff = nums[i + 1] - nums[i];
            // 有0是为了应对有平坡
            if (preDiff <= 0 && curDiff > 0 || preDiff >= 0 && curDiff < 0)
            {
                result++;
                // 如果坡度改变则更新，是为了应对单调有平坡
                preDiff = curDiff;
            }
        }
        return result;
    }
};
// @lc code=end
