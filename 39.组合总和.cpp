/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
public:
    // 单个组合
    vector<int> path;
    // 组合集
    vector<vector<int>> result;

    // candidates无重复元素的正整数数组
    // target目标值
    // sum总和
    // startIndex开始位置
    void backtracking(vector<int> &candidates, int target, int sum, int startIndex)
    {
        // 如果sum>target结束
        if (sum > target)
            return;
        // 如果sum = target存放结果
        if (sum == target)
        {
            result.push_back(path);
            return;
        }

        // 遍历数组中每个元素
        for (int i = startIndex; i < candidates.size(); i++)
        {
            // 存放当前值
            path.push_back(candidates[i]);
            // sum更新
            sum += candidates[i];
            // 递归
            // 递归调用时 startIndex 应该是 i 以允许重复使用当前元素
            // 因为可以有重复元素所以startIndex不变
            backtracking(candidates, target, sum, i);
            // 回溯
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int sum = 0;
        int startIndex = 0;
        backtracking(candidates, target, sum, startIndex);
        return result;
    }
};
// @lc code=end
