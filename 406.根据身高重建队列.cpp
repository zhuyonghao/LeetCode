/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        // 身高降序，当身高相同时k升序
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] > b[0] || a[0] == b[0] && a[1] < b[1]; });

        vector<vector<int>> queue;
        // 根据k来插入vector<int>
        // 因为前面身高大，所以后面的向前插入不影响
        for (const auto &person : people)
        {
            queue.insert(queue.begin() + person[1], person);
        }
        return queue;
    }
};
// @lc code=end
