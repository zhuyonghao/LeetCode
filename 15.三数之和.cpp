/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 用来存放结果
        vector<vector<int>> result;
        // 先排序
        sort(nums.begin(), nums.end());

        // 进行遍历
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果首位大于0返回
            if (nums[i] > 0)
                return result;
            // 对nums进行去重处理
            // nums[i] == nums[i + 1]不可以
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            // 定义左右指针
            int left = i + 1;
            int right = nums.size() - 1;
            // left == right时不再是三个数了
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // 对left和right进行去重

                    while (left < right && nums[right - 1] == nums[right])
                        right--;

                    while (left < right && nums[left + 1] == nums[left])
                        left++;
                    // 统一处理
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};
// @lc code=end
