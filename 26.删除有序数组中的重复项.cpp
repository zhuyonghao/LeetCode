/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
/*
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; ++i)
            while (true)
            {
                int j = i + 1;
                if (nums[i] == nums[j])
                    // erase函数使用迭代器
                    nums.erase(nums.begin() + j);
                else
                    break;
            }
        // 因为删除了元素，for循环中迭代器失效
        return nums.size();
    }
};
*/
// @lc code=end
