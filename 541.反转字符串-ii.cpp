/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
public:
    // 按照地址传递不然不会修改
    void reverse(string &s, int begin, int end)
    {
        int left = begin;
        int right = end - 1;

        while (left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    string reverseStr(string s, int k)
    {
        // 每次移动2k的距离
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            // i + k没有超
            // 2k中的前k个进行反转
            // k < length < 2k的前k个进行反转
            if (i + k <= s.size())
            {
                // 左闭右开区间
                // reverse(s.begin() + i, s.begin() + i + k);
                reverse(s, i, i + k);
            }
            // 如果i+k超了，则没有k个
            // 对i到nums.size进行反转
            else
                // reverse(s.begin() + i, s.end());
                reverse(s, i, s.size());
        }
        return s;
    }
};
// @lc code=end
