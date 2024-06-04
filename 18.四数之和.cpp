/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // 用来存放结果
        vector<vector<int>> result;
        // 排序之后才好使用双指针
        sort(nums.begin(), nums.end());
        // 遍历第一层
        for (int i = 0; i < nums.size(); i++)
        { // 第一次剪枝
            // 只要nums[i] > targrt且nums[i] >= 0
            if (nums[i] > target && nums[i] >= 0)
                return result;
            // 第一次去重
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            // 遍历第二层
            for (int j = i + 1; j < nums.size(); j++)
            { // 第二次剪枝
                // nums[i]+nums[j] >= 0 nums[i]+nums[j] > targrt
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
                    // 因为外面还有一层循环不应该直接return
                    break;
                // 第二次去重
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                // 定义左右指针
                int left = j + 1;
                int right = nums.size() - 1;
                // 寻找target直至left==right
                while (left < right)
                {
                    // 类型转化为long不然会超过
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                        left++;
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                        right--;
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // 去重
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
        }
        return result;
    }
};
// @lc code=end
