/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
/*
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; ++i)
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        return {};
    }
};
*/

// 哈希表
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 用来存放已经遍历过的元素
        unordered_map<int, int> Map;

        // 遍历元素
        for (int i = 0; i < nums.size(); i++)
        {
            // 要查找的元素
            int s = target - nums[i];
            // 查找是否存在该元素
            // find返回一个迭代器
            auto itr = Map.find(s);
            if (itr != Map.end())
            {
                // 如果查询到返回下标
                return {itr->second, i};
            }
            // 如果不存在将已查询的元素放入map中
            Map.insert(make_pair(nums[i], i));
        }
        // 未查询到返回空
        return {};
    }
};

// @lc code=end
