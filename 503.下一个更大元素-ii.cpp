/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> result(n, -1);
        // 单调栈
        stack<int> st;
        // 遍历二倍数组
        for (int i = 0; i < 2 * n; i++)
        {
            // 使用取模进行循环
            while (!st.empty() && nums[i % n] > nums[st.top()])
            {
                result[st.top()] = nums[i % n];
                st.pop();
            }
            // 如果在n的范围内添加
            if (i < n)
                st.push(i);
        }
        return result;
    }
};
// @lc code=end
