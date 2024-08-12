/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        // 记录每个元素的最远出现位置
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            // 不断更新位置直至到最远位置
            hash[s[i] - 'a'] = i;
        }

        int left = 0;
        int right = 0;
        vector<int> result;
        // 寻找分割线
        for (int i = 0; i < s.size(); i++)
        {
            // 不断更新右边界
            // 当前元素的最远位置
            right = max(right, hash[s[i] - 'a']);
            // 如果当前位置是包含首元素的最远位置
            if (i == right)
            {
                // 存放结果
                result.push_back(right - left + 1);
                // 更新左区间
                left = i + 1;
            }
        }
        return result;
    }
};
// @lc code=end
