/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // 定义栈
        stack<int> st;
        // 遇到数字存放进栈
        // 遇到运算符取出两个数字运算后再放入栈中
        for (string s : tokens)
        {
            if (isdigit(s[0]) || (s[0] == '-' && s.size() > 1))
                st.push(stoi(s));
            else
            {
                if (s == "+")
                {
                    // 先出栈的是第二个数
                    int num2 = st.top();
                    st.pop();
                    int num1 = st.top();
                    st.pop();
                    st.push(num1 + num2);
                }
                else if (s == "-")
                {
                    int num2 = st.top();
                    st.pop();
                    int num1 = st.top();
                    st.pop();
                    st.push(num1 - num2);
                }
                else if (s == "*")
                {
                    int num2 = st.top();
                    st.pop();
                    int num1 = st.top();
                    st.pop();
                    st.push(num1 * num2);
                }
                else if (s == "/")
                {
                    int num2 = st.top();
                    st.pop();
                    int num1 = st.top();
                    st.pop();
                    st.push(num1 / num2);
                }
            }
        }
        return st.top();
    }
};
// @lc code=end
