/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // 找左边和右边小的元素
        int n = heights.size();

        if (n == 0)
            return 0;

        // 插入哨兵元素
        // 首位加0便于计算
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        stack<int> st;

        int largestArea = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int height = heights[st.top()];
                st.pop();
                if (st.empty())
                    break;
                int width = i - st.top() - 1;
                largestArea = max(width * height, largestArea);
            }
            st.push(i);
        }
        return largestArea;
    }
};
// @lc code=end
