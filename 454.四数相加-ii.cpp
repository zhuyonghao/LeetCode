/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        // 用来记录个数
        int count = 0;
        // 用来存放要查找的元素和次数
        unordered_map<int, int> Map;
        // 将元素放入容器中
        for (int a : nums1)
            for (int b : nums2)
                Map[a + b]++;

        // 在另外两个容器中进行查找
        for (int c : nums3)
            for (int d : nums4)
            {
                int target = 0 - c - d;
                if (Map.find(target) != Map.end())
                    // 次数加上key所对应的value
                    count += Map[target];
            }
        return count;
    }
};
// @lc code=end
