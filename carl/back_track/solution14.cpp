#include <iostream>
#include <vector>
using namespace std;
/*
https://leetcode.cn/problems/n-queens/description/
N皇后
*/
class Solution
{
private:
    vector<vector<string>> ans;
    /*
    @param: n 为输入的棋盘大小
    @param: row 是当前递归到棋盘的第几行了
    */
    void backtracking(int n, int row, vector<string> &chessboard)
    {
        if (row == n)
        {
            ans.push_back(chessboard);
            return;
        }
        // 深度每行，遍历每列
        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, chessboard, n))
            {
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }

    /*
    (row,col)是否能放1个皇后
    */
    bool isValid(int row, int col, vector<string> &chessboard, int n)
    {
        // 同列
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][col] == 'Q')
            {
                return false;
            }
        }

        // 45度
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }

        // 135度
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        ans.clear();
        // nxn棋盘，棋盘元素值为.
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return ans;
    }
};