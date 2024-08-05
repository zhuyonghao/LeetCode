/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
public:
    vector<int> path;           // 单个组合
    vector<vector<int>> result; // 组合集
    int sum = 0;                // sum当前和
    int startIndex = 1;         // startIndex起始位置
    // n组合目标和
    // k组合数量

    void backtracking(int n, int k, int sum, int startIndex)
    {
        // 如果遇到叶子节点返回
        if (path.size() == k)
        {
            // 如果当前和和目标和相等，将组合放入结果中
            if (sum == n)
                result.push_back(path);
            return;
        }

        // 如果当前值大于目标值返回
        if (sum > n)
            return;

        // for循环遍历每个元素
        // 对元素进行剪枝
        // 还需要元素个数k-path.size()
        // 个数最大位置9-(k-path.size()) + 1
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
        {
            // 将当前值放入组合中
            path.push_back(i);
            // 计算和
            sum += i;
            // 递归
            backtracking(n, k, sum, i + 1);
            // 回溯
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(n, k, sum, startIndex);
        return result;
    }
};
// @lc code=end
