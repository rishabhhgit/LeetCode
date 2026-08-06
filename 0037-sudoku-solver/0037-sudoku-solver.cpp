class Solution {
public:
    bool row[9][9] = {false}, col[9][9] = {false}, box[9][9] = {false};

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '1';
                    row[i][val] = col[j][val] = box[(i / 3) * 3 + (j / 3)][val] = true;
                }
            }
        }
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, int r, int c) {
        if (r == 9) return true;
        int nextR = (c == 8) ? r + 1 : r;
        int nextC = (c == 8) ? 0 : c + 1;

        if (board[r][c] != '.') return backtrack(board, nextR, nextC);

        for (int i = 0; i < 9; ++i) {
            int b = (r / 3) * 3 + (c / 3);
            if (!row[r][i] && !col[c][i] && !box[b][i]) {
                board[r][c] = i + '1';
                row[r][i] = col[c][i] = box[b][i] = true;
                if (backtrack(board, nextR, nextC)) return true;
                board[r][c] = '.';
                row[r][i] = col[c][i] = box[b][i] = false;
            }
        }
        return false;
    }
};
