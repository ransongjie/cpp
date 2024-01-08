#include <iostream>
#include <vector>
using namespace std;
/*
https://leetcode.cn/problems/sudoku-solver/
解数独
*/
class Solution
{
private:
    bool backtracking(vector<vector<char>> &board)
    {
        // 遍历行
        for (int i = 0; i < board.size(); i++)
        {
            // 遍历列
            for (int j = 0; j < board[0].size(); j++)
            { // board[0].size() 每列size相等
                if (board[i][j] == '.')
                {
                    // 尝试每个数字
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if (isValid(i, j, k, board))
                        {
                            board[i][j] = k;
                            // 有1个解法即可返回
                            if (backtracking(board))
                            {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    // 尝试每个数字，都失败
                    return false;
                }
            }
        }
        // 遍历完没有返回false，说明找到了解
        return true;
    }
    bool isValid(int row, int col, char val, vector<vector<char>> &board)
    {
        // 第row行中是否已经有val
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == val)
            {
                return false;
            }
        }
        // 第col列中是否已经有val
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == val)
            {
                return false;
            }
        }
        // 9小格中是否已经有val
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) // +3因为是3*3的格子
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (board[i][j] == val)
                {
                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }
};