/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        // 按照绝对值从大到小排序
        sort(nums.begin(), nums.end(), cmp);

        for (int i = 0; i < nums.size(); i++)
        {
            // 如果遇到负数取反
            if (nums[i] < 0 && k > 0)
            {
                nums[i] = -nums[i];
                k--;
            }
        }

        // 如果k为偶数反复取反等于没取
        // 如果k为奇数对最小绝对值的数进行取反
        if (k % 2 == 1)
            nums[nums.size() - 1] = -nums[nums.size() - 1];

        int sum = 0;
        // 求和
        for (int num : nums)
            sum += num;
        return sum;
    }
};
// @lc code=end
