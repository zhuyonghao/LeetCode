/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalSum = 0; // 总和
        int curSum = 0;   // 当前和
        int start = 0;    // 起始位置

        // 统计总和，如果小于0则直接返回
        for (int i = 0; i < gas.size(); i++)
            totalSum += gas[i] - cost[i];
        if (totalSum < 0)
            return -1;

        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            // 如果curSum小于0，则更新开始位置
            if (curSum < 0)
            {
                start = i + 1; // 更新下一位
                curSum = 0;    // 和置为0
            }
        }
        // 返回开始位置
        return start;
    }
};
// @lc code=end
