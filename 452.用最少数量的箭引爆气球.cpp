/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;

        // 按照起始位置从小到大排序
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        int result = 1; // 不为空至少需要一个箭
        for (int i = 0; i < points.size() - 1; i++)
        {
            // 如果右边界小于下一个左边界
            if (points[i][1] < points[i + 1][0])
                result++;
            else
                // 更新下一个右边界
                points[i + 1][1] = min(points[i][1], points[i + 1][1]);
        }
        return result;
    }
};
// @lc code=end
