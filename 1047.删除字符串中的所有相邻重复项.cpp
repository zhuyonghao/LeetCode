/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        // 用字符串模拟栈
        string result;

        for (char str : s)
        {
            // 栈为空或栈顶元素不相等时放入
            if (result.empty() || str != result.back())
                result.push_back(str);
            else
            {
                // 如果相等则删除
                result.pop_back();
            }
        }
        // 返回栈中元素
        return result;
    }
};
// @lc code=end
