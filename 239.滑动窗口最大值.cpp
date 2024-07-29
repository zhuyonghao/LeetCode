/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
public:
    deque<int> dq;

    // 单调递减的队列
    void push(int value)
    {
        // 如果比最后一个元素大移除最后一位元素直至前面没有比他大的元素
        while (!dq.empty() && value > dq.back())
        {
            dq.pop_back();
        }
        // 如果比最后一个元素小直接放入
        dq.push_back(value);
    }

    void pop(int value)
    {
        // 如果移除的元素比队列开头元素小则不用移除因为前面push操作已经移除了
        if (!dq.empty() && value == dq.front())
            dq.pop_front();
    }

    // 最大值：返回队列开头元素
    int getMaxValue()
    {
        return dq.front();
    }

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;

        // 将开头元素放入队列中
        for (int i = 0; i < k; i++)
        {
            push(nums[i]);
        }

        // 将最大值放入结果中
        ans.push_back(getMaxValue());

        // 后面开始去一位加一位
        for (int i = k; i < nums.size(); i++)
        {
            pop(nums[i - k]);
            push(nums[i]);
            // 将最大值放入队列中
            ans.push_back(getMaxValue());
        }

        return ans;
    }
};
// @lc code=end
