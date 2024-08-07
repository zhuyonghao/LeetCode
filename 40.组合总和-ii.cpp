/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, int target, int sum, int startIndex, vector<bool> &used)
    {
        // 终止条件
        if (sum > target)
            return;

        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        // 遍历元素
        for (int i = startIndex; i < nums.size(); i++)
        {
            // 如果前一个元素和当前元素相等并且未使用过
            // 说明已经遍历到第二个元素可以直接跳过
            // 如果前一个元素和当前元素相等并且使用过
            // 可以继续遍历
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            // 更新
            path.push_back(nums[i]);
            sum += nums[i];
            used[i] = true;
            // 递归
            backtracking(nums, target, sum, i + 1, used);
            // 回溯
            path.pop_back();
            sum -= nums[i];
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // 用来存放遍历过的元素
        vector<bool> used(candidates.size(), false);
        // 排序
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};
// @lc code=end
