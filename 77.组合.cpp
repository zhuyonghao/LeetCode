/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    vector<int> path;           // 单个组合
    vector<vector<int>> result; // 组合集，存放结果
    int startIndex = 1;         // 遍历的起始位置
    void backtracking(int n, int k, int startIndex)
    {
        // 遇到长度为k的叶子节点返回
        if (path.size() == k)
        {
            // 将结果记录
            result.push_back(path);
            return;
        }
        // for循环选取元素，在这个地方进行剪枝操作
        // 还需要k-path.size()个元素
        // 至多从 n - (k - path.size() + 1)的位置开始
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)
        {
            // 将当前值放入path中
            path.push_back(i);
            // 递归
            backtracking(n, k, i + 1);
            // 回溯
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, startIndex);
        return result;
    }
};
// @lc code=end
