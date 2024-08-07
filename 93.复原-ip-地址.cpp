/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s, int start, int end)
    {
        // 开头比结尾大
        if (start > end)
            return false;
        // 开头为0
        if (s[start] == '0' && start < end)
            return false;

        int sum = 0; // 记录总和
        // 遍历每个元素
        for (int i = start; i <= end; i++)
        {
            if (s[i] < '0' && s[i] > '9')
                return false;
            sum = sum * 10 + (s[i] - '0');
            if (sum > 255)
                return false;
        }
        return true;
    }

    vector<string> result; // 存放结果
    // pointNum记录点数
    void backtracking(string &s, int startIndex, int pointNum)
    {
        // 点数为3收集结果
        if (pointNum == 3)
        {
            if (isValid(s, startIndex, s.size() - 1))
                result.push_back(s);
            return;
        }

        // 遍历元素
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isValid(s, startIndex, i))
            {
                s.insert(s.begin() + i + 1, '.'); // 插入点
                pointNum++;                       // 点数加一
                // 递归
                backtracking(s, i + 2, pointNum); // i+2因为多了一个点
                // 回溯
                pointNum--;
                s.erase(s.begin() + i + 1);
            }
            else
                break;
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        backtracking(s, 0, 0);
        return result;
    }
};
// @lc code=end
