/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, int startIndex)
    {
        // 长度大于1开始收集结果
        if (path.size() > 1)
            result.push_back(path);
        // startIndex如果长度超出了nums则返回
        if (startIndex >= nums.size())
            return;
        // 将每层递归遍历过的元素记录
        unordered_set<int> uset;
        // 遍历每一个元素
        for (int i = startIndex; i < nums.size(); i++)
        {
            // 如果当前元素比前一个元素小则剪枝
            // 或者当前元素已经出现也剪枝
            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end())
                continue;
            // 更新
            path.push_back(nums[i]);
            // 将当前元素放入set中
            uset.insert(nums[i]);
            // 递归
            backtracking(nums, i + 1);
            // 回溯
            path.pop_back();
            // 因为uset每一层需要记录重复元素并且是局部变量所以不用回溯
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        // 不使用排好序和used数组的元素:会增加递增子序列的数目
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end
