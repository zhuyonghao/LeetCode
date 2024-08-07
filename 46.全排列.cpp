/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        // 收集叶子节点
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        // startIndex是防止出现组合的重复12和21
        // 遍历每个元素使用used数组避免相同元素多次取
        for (int i = 0; i < nums.size(); i++)
        {
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end
