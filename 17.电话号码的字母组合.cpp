/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    // 使用二维数组进行映射
    string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // 存放单个组合
    string s;
    // 存放结果
    vector<string> result;

    // digits传入的数字集合
    // index当前数字下标从0开始
    void backtracking(string digits, int index)
    {
        // 当组合长度等于数字集合的数目
        if (s.size() == digits.size())
        {
            result.push_back(s);
            return;
        }

        // 数字下标对应的数字
        int digit = digits[index] - '0';
        // 数字对应的字符串
        string letter = letters[digit];

        // 遍历字符串
        for (int i = 0; i < letter.size(); i++)
        {
            // 将当前值放入组合中
            s.push_back(letter[i]);
            // 递归
            backtracking(digits, index + 1); // backtracking(digits, index + 1, letter[i])隐藏回溯
            // 回溯
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        backtracking(digits, 0);
        return result;
    }
};
// @lc code=end
