/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for (int bill : bills)
        {
            // 如果支付为5不用找零
            if (bill == 5)
                five++;
            // 如果支付10找零5
            else if (bill == 10)
            {
                // 如果有5
                if (five > 0)
                {
                    five--;
                    ten++;
                }
                else
                    return false; // 没有5则false
            }
            // 优先找10 + 5
            // 其次 5 5 5
            else if (bill == 20)
            {
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                    twenty++;
                }
                else if (five >= 3)
                {
                    five -= 3;
                    twenty++;
                }
                else
                    return false; // 如果都没有则返回false
            }
        }
        // 如果都满足返回true
        return true;
    }
};
// @lc code=end
