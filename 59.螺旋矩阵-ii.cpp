/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> nums(n, vector<int>(n, 0));

        int i = 0;
        int j = 0; // 下标

        int offset = 1; // 循环不变量 控制区间

        int startX = 0;
        int startY = 0; // 旋转一圈后起始位置不同

        int count = 1;

        int loop = n / 2;

        while (loop--) // 每旋转一圈减少两行两列
        {
            j = startY;
            i = startX; // 初始化i和j

            for (; j < n - offset; j++)
                nums[i][j] = count++;
            for (; i < n - offset; i++)
                nums[i][j] = count++;
            for (; j > startY; j--)
                nums[i][j] = count++;
            for (; i > startX; i--)
                nums[i][j] = count++;

            startX++;
            startY++;
            offset++;
        }
        if (n % 2 == 1)
            nums[n / 2][n / 2] = count;
        return nums;
    }
};
// @lc code=end
