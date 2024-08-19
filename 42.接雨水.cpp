/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        stack<int> st; // 存放下标
        int water_trapped = 0;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && height[i] > height[st.top()])
            {
                int h = height[st.top()]; // 弹出的柱子的高度
                st.pop();
                // 如果栈为空，说明没有足够的柱子来计算雨水量，跳出循环
                if (st.empty())
                    break;
                int width = i - st.top() - 1;
                int height_bounded = min(height[i], height[st.top()]) - h; // 减去当前弹出的柱子 h 的高度。
                water_trapped += width * height_bounded;
            }
            st.push(i);
        }
        return water_trapped;
    }
};
// @lc code=end
