/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> result;

    // row 行
    // col 列
    // n 棋盘行数
    bool isValid(vector<string> chessboard, int row, int col, int n)
    {
        // 不用判断行，因为每次递归从行中取一个元素
        // 判断列
        // 因为递归只需要判断当前行之前是否出现Q
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][col] == 'Q')
                return false;
        }

        // 判断45上
        // 行与列必须都大于等于0
        // for循环中不能同时声明两个变量。应该分别声明int i = row - 1, int j = col - 1
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }

        // 判断135上
        // 行要>=0，列应该小于n而不是小于等于n
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }

        // 都成立
        return true;
    }

    void backtracking(vector<string> &chessboard, int row, int n)
    {
        // 当前行是最大行返回
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }
        // 遍历每一行的每个元素
        for (int col = 0; col < n; col++)
        {
            // 如果有效继续遍历，无效则终止
            if (isValid(chessboard, row, col, n))
            {
                // 更新
                chessboard[row][col] = 'Q';
                // 递归下一行
                backtracking(chessboard, row + 1, n);
                // 回溯
                chessboard[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(chessboard, 0, n);
        return result;
    }
};
// @lc code=end
