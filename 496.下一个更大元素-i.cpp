/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // 用来存放nums2中每个元素右边第一个更大的元素
        unordered_map<int, int> nextGreater;
        // 单调栈 存放元素
        stack<int> st;
        // 存放结果
        vector<int> ans;

        for (int num : nums2)
        {
            // 当前元素比栈元素大
            while (!st.empty() && num > st.top())
            {
                nextGreater[st.top()] = num;
                st.pop();
            }
            // 当前元素小于放入
            st.push(num);
        }

        // 将剩余元素初始化为1
        while (!st.empty())
        {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // 查询nums1中的在nums2每一个元素右边较大的元素
        for (int num : nums1)
            ans.push_back(nextGreater[num]);

        return ans;
    }
};
// @lc code=end
