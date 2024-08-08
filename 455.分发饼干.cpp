/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // 排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;     // 指向胃口大小
        int j = 0;     // 指向饼干大小
        int count = 0; // 记录满足小孩数量

        // 在胃口和饼干的范围内
        while (i < g.size() && j < s.size())
        {
            // 如果满足都想后移动
            if (g[i] <= s[j])
            {
                i++;
                j++;
                count++;
            }
            // 如果不满足，饼干大小增大
            else
                j++;
        }
        return count;
    }
};
// @lc code=end
