/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int hashTable[26];

        // 统计s中每个字符出现的次数
        for (int i = 0; i < s.size(); i++)
            hashTable[s[i] - 'a']++;

        // t中进行减减操作，最终数组的值如果不为0则不相同
        for (int i = 0; i < t.size(); i++)
            hashTable[t[i] - 'a']--;

        for (int i : hashTable)
            if (i != 0)
                return false;
        return true;
    }
};
// @lc code=end
