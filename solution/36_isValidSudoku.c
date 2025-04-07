/*
 * @lc app=leetcode.cn id=36 lang=c
 *
 * [36] 有效的数独
 */

// @lc code=start
bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    bool rc = true;
    char row[9][9] = {0};
    char col[9][9] = {0};
    char box[9][9] = {0};

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            int boxI = i / 3;
            int boxJ = j / 3;
            int boxIdx = boxJ * 3 + boxI;
            if (row[i][board[i][j] - '1'] == 1 ||
                col[j][board[i][j] - '1'] == 1 || 
                box[boxIdx][board[i][j] - '1'] == 1) {
                rc = false;
                goto l_end;
            }
            row[i][board[i][j] - '1'] = 1;
            col[j][board[i][j] - '1'] = 1;
            box[boxIdx][board[i][j] - '1'] = 1;
        }
    }
    
l_end:
    return rc;
}
// @lc code=end

