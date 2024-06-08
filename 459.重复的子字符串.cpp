/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // 两个字串相加
        string t = s + s;
        // 掐头去尾
        t.erase(t.begin());
        t.erase(t.end() - 1);
        // 判断是否找到
        // 找到就有，找不到就没有
        // O(m + n)
        if (t.find(s) != string::npos)
            return true;
        return false;
    }
};
// @lc code=end
