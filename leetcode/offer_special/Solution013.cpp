#include <iostream>
#include <vector>
using namespace std;
/**
 * 二维子矩阵的和
 */
class NumMatrix
{
private:
    vector<vector<int>> sums;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int i = 0, j = 0, m = matrix.size(), n = matrix[0].size();
        sums.resize(m + 1, vector<int>(n + 1));//
        sums[0][0] = 0;
        for (; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                sums[i + 1][j + 1] = sums[i + 1][j] + sums[i][j + 1] - sums[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];
    }
};