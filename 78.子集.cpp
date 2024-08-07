/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, int startIndex)
    {
        // 进入每层递归都要收集结果
        result.push_back(path);

        // 该终止条件可以省略
        if (startIndex >= nums.size())
            return;

        for (int i = startIndex; i < nums.size(); i++)
        {
            // 放入
            path.push_back(nums[i]);
            // 递归
            backtracking(nums, i + 1);
            // 回溯
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end
