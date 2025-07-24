#include <iostream>
#include <vector>
using namespace std;

// Worst-case time complexity: O(9^E)
// (where E = number of empty cells)

bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
    // Check row
    for (int j = 0; j < 9; j++) {
        if (board[row][j] == dig) return false;
    }
    // Check column
    for (int j = 0; j < 9; j++) {
        if (board[j][col] == dig) return false;
    }
    // Check 3x3 grid
    int srow = (row / 3) * 3;
    int scol = (col / 3) * 3;
    for (int i = srow; i < srow + 3; i++) {
        for (int j = scol; j < scol + 3; j++) {
            if (board[i][j] == dig) return false;
        }
    }
    return true;
}

bool helper(vector<vector<char>>& board, int row, int col) {
    if (row == 9) return true;

    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    if (board[row][col] != '.') {
        return helper(board, nextRow, nextCol);
    }

    for (char dig = '1'; dig <= '9'; dig++) {
        if (isSafe(board, row, col, dig)) {
            board[row][col] = dig;
            if (helper(board, nextRow, nextCol)) return true;
            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    helper(board, 0, 0);
}

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& c : row) {
            cout << c << ' ';
        }
        cout << '\n';
    }
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Original Sudoku:\n";
    printBoard(board);

    solveSudoku(board);

    cout << "\nSolved Sudoku:\n";
    printBoard(board);

    return 0;
}
