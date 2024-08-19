/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        // 存放结果默认为0
        vector<int> result(n, 0);
        // 使用单调栈存放位置
        stack<int> st;
        // 遍历每个元素
        for (int i = 0; i < n; i++)
        {
            // 不断比较直至栈为空
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end
