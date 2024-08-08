/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
public:
    bool isValid(int row, int col, char k, vector<vector<char>> &board)
    {
        // 检查每行每列是否有重复元素
        for (int i = 0; i < 9; i++)
        {
            // 行
            if (board[row][i] == k)
                return false;
            // 列
            if (board[i][col] == k)
                return false;
        }

        // 检查3*3中是否有重复元素
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
            for (int j = startCol; j < startCol + 3; j++)
                if (board[i][j] == k)
                    return false;

        // 都成立
        return true;
    }

    // 只需要返回一个结果使用bool
    bool backtracking(vector<vector<char>> &board)
    {
        // 无终止条件因为棋盘被填满就结束

        // 在9*9的棋盘里寻找空元素
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    // 如果找到了进行填数
                    for (char k = '1'; k <= '9'; k++)
                    {
                        // 检查填入的数是否符合要求
                        if (isValid(row, col, k, board))
                        {
                            // 如何要求就填入
                            board[row][col] = k;
                            // 进行递归 如果找到一个就立刻返回不需要继续执行
                            if (backtracking(board))
                                return true;
                            // 回溯
                            board[row][col] = '.';
                        }
                    }
                    // 如果9个数都不可以则返回false
                    return false;
                }
            }
        }
        // 遍历完所有空元素返回true
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }
};
// @lc code=end
