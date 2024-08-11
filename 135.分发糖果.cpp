/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // 如果右边比左边大
        vector<int> Rcandys(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                Rcandys[i] = Rcandys[i - 1] + 1;
        }

        // 如果左边比右边大
        vector<int> Lcandys(ratings.size(), 1);

        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                Lcandys[i] = Lcandys[i + 1] + 1;
        }
        // 比较取最大值则可以满足即大于右边也大于左边
        for (int i = 0; i < Rcandys.size(); i++)
            Rcandys[i] = max(Rcandys[i], Lcandys[i]);

        // 求和
        int sum = 0;
        for (int candy : Rcandys)
            sum += candy;
        return sum;
    }
};
// @lc code=end
