/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;
        // 按照左区间从小到大排序
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        int result = 0; // 要删除的个数
        for (int i = 0; i < intervals.size() - 1; i++)
        {
            // 如果右区间大于下一个左区间则重叠需要删除
            if (intervals[i][1] > intervals[i + 1][0])
            {
                result++;
                // 更新右区间
                intervals[i + 1][1] = min(intervals[i][1], intervals[i + 1][1]);
            }
            // 如果右区间小于等于下一个左区间不需要操作
        }
        return result;
    }
};
// @lc code=end
