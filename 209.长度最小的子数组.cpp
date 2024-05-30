/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
/*
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int len = INT32_MAX;
        bool isExit = false;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = nums[i];
            if (nums[i] >= target)
                return 1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum >= target)
                {
                    isExit = true;
                    len = ((j - i + 1) > len ? len : j - i + 1);
                    break;
                }
                else if (sum < target)
                    continue;
            }
        }
        if (isExit)
            return len;
        return 0;
    }
};
*/
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT32_MAX;
        int slow = 0;
        int sum = 0;
        for (int fast = 0; fast < nums.size(); ++fast)
        {
            sum += nums[fast];
            while (sum >= target)
            {
                result = (fast - slow + 1 > result ? result : fast - slow + 1);
                sum -= nums[slow];
                slow++;
            }
        }
        return (result == INT32_MAX ? 0 : result);
    }
};
// @lc code=end
