/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
// class Solution
// {
// public:
//     vector<vector<int>> merge(vector<vector<int>> &intervals)
//     {
//         if (intervals.size() <= 1)
//             return intervals;
//         // 根据左区间从小到大排序
//         sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
//              { return a[0] < b[0]; });

//         vector<vector<int>> result;
//         for (int i = 0; i < intervals.size() - 1; i++)
//         {
//             // 如果右区间大于下一位左区间
//             if (intervals[i][1] >= intervals[i + 1][0])
//             {
//                 // 更新左区间
//                 intervals[i + 1][0] = intervals[i][0];
//                 // 更新右区间
//                 intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
//                 // 最后一个区间需要特殊处理
//                 if (i + 1 == intervals.size() - 1)
//                     result.push_back(intervals[i + 1]);
//             }
//             else
//             {
//                 result.push_back(intervals[i]);
//                 // 最后一个区间需要特殊处理
//                 if (i + 1 == intervals.size() - 1)
//                     result.push_back(intervals[i + 1]);
//             }
//         }
//         return result;
//     }
// };

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return intervals;
        // 根据左区间从小到大排序
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        vector<vector<int>> result;
        // 放入开头元素特殊处理
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            // 如果当前左区间小于等于原来的右区间
            if (intervals[i][0] <= result.back()[1])
            {
                // 更新原来的右区间
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
// @lc code=end
