/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
public:
    vector<string> path;
    vector<vector<string>> result;

    bool isPalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void backtracking(string s, int startIndex)
    {
        // 终止条件
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
        // 遍历元素
        for (int i = startIndex; i < s.size(); i++)
        {
            // 如果是回文数则保存
            if (isPalindrome(s, startIndex, i))
            {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else
                continue;
            // 递归
            backtracking(s, i + 1);
            // 回溯
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return result;
    }
};
// @lc code=end
