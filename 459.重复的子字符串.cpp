/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
// class Solution
// {
// public:
//     bool repeatedSubstringPattern(string s)
//     {
//         // 两个字串相加
//         string t = s + s;
//         // 掐头去尾
//         t.erase(t.begin());
//         t.erase(t.end() - 1);
//         // 判断是否找到
//         // 找到就有，找不到就没有
//         // O(m + n)
//         if (t.find(s) != string::npos)
//             return true;
//         return false;
//     }
// };
class Solution
{
public:
    // 得到前缀表
    vector<int> getPrefix(const string &pattern)
    {
        int i = pattern.length();
        vector<int> prefix(i, 0);
        int k = 0;
        for (int j = 1; j < i; j++)
        {
            while (pattern[j] != pattern[k] && k > 0)
            {
                k = prefix[k - 1];
            }
            if (pattern[j] == pattern[k])
                k++;
            prefix[j] = k;
        }
        return prefix;
    }
    bool repeatedSubstringPattern(string s)
    {
        vector<int> prefix = getPrefix(s);
        int i = s.length();
        if (prefix[i - 1] != 0 && (i % (i - prefix[i - 1]) == 0))
            return true;
        return false;
    }
};

// @lc code=end
