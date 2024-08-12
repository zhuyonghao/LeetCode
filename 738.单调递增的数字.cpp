/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        // 转换成string
        string str = to_string(n);

        int flag = str.size();
        // 从后往前遍历确保递增
        for (int i = str.size() - 1; i > 0; i--)
        {
            // i - 1所以i > 0
            // 不满足单调递增
            if (str[i - 1] > str[i])
            {
                str[i - 1]--;
                str[i] = '9';
                flag = i;
            }
        }
        // 2300让2290 变成2299
        for (int i = flag; i < str.size(); i++)
            str[i] = '9';
        // 转换成整型
        return stoi(str);
    }
};
// @lc code=end
