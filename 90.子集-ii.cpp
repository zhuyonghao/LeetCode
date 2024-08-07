/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, int startIndex, vector<bool> &used)
    {
        // 进入每层递归收集结果
        result.push_back(path);
        // 终止条件
        if (startIndex >= nums.size())
            return;
        // 遍历每个元素
        for (int i = startIndex; i < nums.size(); i++)
        {
            // 如果前一个元素和后一个元素相等且未使用继续遍历
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false)
                continue;
            // 更新
            path.push_back(nums[i]);
            used[i] = true;
            // 递归
            backtracking(nums, i + 1, used);
            // 回溯
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        // 排序
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return result;
    }
};
// @lc code=end
