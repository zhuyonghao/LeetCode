/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        // 排列从0开始遍历
        for (int i = 0; i < nums.size(); i++)
        {
            // 广度上去重
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            // 防止重复元素多次取
            if (used[i] == true)
                continue;
            // 更新
            path.push_back(nums[i]);
            used[i] = true;
            // 递归
            backtracking(nums, used);
            // 回溯
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // used防止广度上重复
        // used防止深度上相同元素多次取
        vector<bool> used(nums.size(), false);
        // 排序是为了去重
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end
