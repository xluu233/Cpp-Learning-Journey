//
// Created by A on 2023/7/14.
//
#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {

private:
    std::vector<std::vector<int>> vecSum;

public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        if(n == 0) return;

        vecSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                vecSum[i][j] = vecSum[i-1][j] + vecSum[i][j-1] - vecSum[i-1][j-1] + matrix[i-1][j-1];
                std::cout << "i:" << i << "  j:" << j << "   " << vecSum[i][j] << std::endl;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return vecSum[row2+1][col2+1] - vecSum[row2+1][col1] - vecSum[row1][col2+1] + vecSum[row1][col1];
    }
};


/*

class NumMatrix {
private:
    // preSum[i][j] 记录矩阵 [0, 0, i, j] 的元素和
    vector<vector<int>> preSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return;
        // 构造前缀和矩阵
        preSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 计算每个矩阵 [0, 0, i, j] 的元素和
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i - 1][j - 1] - preSum[i-1][j-1];
                std::cout << "i:" << i << "  j:" << j << "   " << preSum[i][j] << std::endl;
            }
        }
    }

    // 计算子矩阵 [x1, y1, x2, y2] 的元素和
    int sumRegion(int x1, int y1, int x2, int y2) {
        // 目标矩阵之和由四个相邻矩阵运算获得
        return preSum[x2+1][y2+1] - preSum[x1][y2+1] - preSum[x2+1][y1] + preSum[x1][y1];
    }
};
*/

int main(){

    std::vector<std::vector<int>> matrix = {
            {3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}
    };
    NumMatrix numMatrix(matrix);

    int res = numMatrix.sumRegion(2,1,4,3);

    std::cout << res << std::endl;

}