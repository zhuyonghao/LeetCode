/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;
        // 定义向量大小
        vector<int> result(nums.size());
        while (i <= j)
        {
            if (nums[i] * nums[i] < nums[j] * nums[j])
            {
                result[k] = nums[j] * nums[j];
                k--;
                j--;
            }
            else
            {
                result[k] = nums[i] * nums[i];
                k--;
                i++;
            }
        }
        return result;
    }
};
// @lc code=end
