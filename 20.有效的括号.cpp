/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    // 左边多了
    // 右边多了
    // 不匹配
    bool isValid(string s)
    {
        // 用来存放字符串的栈
        stack<char> st;

        // 剪枝
        if (s.size() % 2 != 0)
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(')');
            if (s[i] == '[')
                st.push(']');
            if (s[i] == '{')
                st.push('}');
            if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (st.empty())
                    return false;
                if (s[i] != st.top())
                    return false;
                else
                    st.pop();
            }
        }
        // 遍历完之后栈不为空
        if (!st.empty())
            return false;
        else
            return true;
    }
};
// @lc code=end
