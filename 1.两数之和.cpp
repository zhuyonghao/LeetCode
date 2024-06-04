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

/*
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
*/

// 双指针
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 排序后下标发生变化
        // 故将其存入hash table
        // 但是具有重复元素哈希表失效
        // 所以此题需要在无重复元素的情况下

        // 去重
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target / 2)
            {
                result.push_back(i);
                if (result.size() == 2)
                    return result;
            }

        map<int, int> Map;
        for (int i = 0; i < nums.size(); i++)
        {
            Map[nums[i]] = i;
        }
        // 排序
        sort(nums.begin(), nums.end());
        // 定义左右指针
        int left = 0;
        int right = nums.size() - 1;
        // 移动指针直至指针相等
        while (left <= right)
        {
            if (nums[left] + nums[right] == target)
                return {Map[nums[left]], Map[nums[right]]};
            else if (nums[left] + nums[right] < target)
                left++;
            else
                right--;
        }

        return {};
    }
};
// @lc code=end
