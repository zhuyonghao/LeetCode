/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    // 比较类
    class mycomparision
    {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            // minHeap 中的元素会按照频率（第二个元素）的升序排列，即频率最低的元素在堆顶
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 统计元素的哈希表
        unordered_map<int, int> frequencyMap;

        // 统计频率
        for (int num : nums)
            frequencyMap[num]++;

        // 使用小顶堆，pop掉较小的的元素得到较大的元素
        // 将哈希表的值放入优先队列中
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparision> minHeap;

        for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it)
        {
            minHeap.push(*it);
            // 如果超出则踢出K+1位
            if (minHeap.size() > k)
                minHeap.pop();
        }

        // 存放k个元素的result数组
        vector<int> result(k);

        for (int i = k - 1; i >= 0; i--)
        {
            // 将最小的频率的pair的值赋值给数组的最后一位
            result[i] = minHeap.top().first;
            // 然后弹出
            minHeap.pop();
        }
        return result;
    }
};
// @lc code=end
