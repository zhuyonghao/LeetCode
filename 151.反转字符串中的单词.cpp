/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        // 定义快慢指针
        int slow = 0;
        // 去空格
        for (int fast = 0; fast < s.size(); fast++)
        {
            // fast找到值
            if (s[fast] != ' ')
            {
                // 不是开头的慢指针保留一个空格
                if (slow != 0)
                {
                    s[slow] = ' ';
                    slow++;
                }
                // 快指针遇到值将后面几个值全赋给慢指针
                // fast不为空，fast不超范围
                while (s[fast] != ' ' && fast < s.size())
                {
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
            }
        }
        // slow指向要赋值的下一位
        // 调整s大小
        s.resize(slow);

        // 先整体翻转
        reverse(s.begin(), s.end());

        // 部分翻转
        int start = 0;

        for (int i = 0; i < s.size() + 1; i++)
        {
            if (s[i] == ' ' || i == s.size())
            {
                // 左闭右开区间
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};
// @lc code=end
