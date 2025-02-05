/*
 * @lc app=leetcode.cn id=48 lang=c
 *
 * [48] 旋转图像
 */

// @lc code=start
void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int row;
    int col;
    int tmp;
    for (row = 0; row < matrixSize / 2; row++) {
        for (col = row; col < matrixSize - row - 1; col++) {
            tmp = matrix[row][col];
            matrix[row][col] = matrix[matrixSize - col - 1][row];
            matrix[matrixSize - col - 1][row] = matrix[matrixSize - row - 1][matrixSize - col - 1];
            matrix[matrixSize - row - 1][matrixSize - col - 1] = matrix[col][matrixSize - row - 1];
            matrix[col][matrixSize - row - 1] = tmp;
        }
    }
}
// @lc code=end

