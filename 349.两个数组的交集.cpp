/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
/*
// set
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 定义一个无序集合
        // 底层用哈希实现，映射和取值比红黑树少了搜索
        unordered_set<int> result_set;

        // 将num1转化为哈希表
        // 用迭代器的方式初始化
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());

        // 在nums1中进行查找是否有nums2
        for (int num : nums2)
            if (nums1_set.find(num) != nums1_set.end())
                // 未找到则迭代器指向结尾
                // 如果找到将其插入到结果中
                // unordered_set实现自动去重
                result_set.insert(num);
        // 返回向量
        return vector<int>(result_set.begin(), result_set.end());
    }
};
*/
// 数组
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 存放结果 去重
        unordered_set<int> result_set;

        // 防止越界
        int hashTable[1005]{0};

        // 将num1进行哈希映射
        for (int num : nums1)
            hashTable[num] = 1;

        for (int num : nums2)
            // 出现的值所对应的值为一
            if (hashTable[num] == 1)
                result_set.insert(num);

        return vector<int>(result_set.begin(), result_set.end());
    }
};
// @lc code=end
