class Solution {

public:
    void nqueen(int col, vector<vector<string>>& ans, vector<string>& board,
                vector<int>& leftRow, vector<int>& upperDiagonal,
                vector<int> lowerDiagonal, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && upperDiagonal[row + col] == 0 &&
                lowerDiagonal[(n - 1) + (col - row)] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[row + col] = 1;
                lowerDiagonal[(n - 1) + (col - row)] = 1;
                nqueen(col + 1, ans, board, leftRow, upperDiagonal,
                       lowerDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[row + col] = 0;
                lowerDiagonal[(n - 1) + (col - row)] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0),
            lowerDiagonal(2 * n - 1, 0);

        nqueen(0, ans, board, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};

/*
PATTERN: N-Queens using Backtracking + Hashing

IDEA:
We place queens column by column.
For each column, we try all rows.

Before placing a queen at (row, col), we check:
1. Is the row already occupied? → leftRow[row]
2. Is the lower diagonal occupied? → lowerDiagonal[row + col]
3. Is the upper diagonal occupied? → upperDiagonal[n - 1 + col - row]

WHY ONLY THESE?
- We move left → right (column-wise)
- So no need to check right side
- Only need to check previously placed queens

DATA STRUCTURES:
- leftRow[n] → tracks rows
- lowerDiagonal[2n-1] → (row + col)
- upperDiagonal[2n-1] → (n-1 + col - row)

STEPS (Backtracking):
1. Try placing queen at (row, col)
2. Mark row & diagonals as occupied
3. Recurse to next column
4. Backtrack (remove queen and unmark)

BASE CASE:
If col == n → all queens placed → store solution

TIME COMPLEXITY:
Optimized to ~O(N!) (due to pruning using hashing)
*/