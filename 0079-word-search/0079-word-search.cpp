class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && solve(board, word, 0, i, j, m, n))
                    return true;
            }
        }
        return false;
    }

private:
    bool solve(vector<vector<char>>& board, string& word, int idx, int row,
               int col, int m, int n) {
        if (idx == word.size())
            return true; // If we found the full word, return true
        if (row < 0 || row >= m || col < 0 || col >= n ||
            board[row][col] != word[idx])
            return false; // Out of bounds or character mismatch

        char temp = board[row][col]; // Store the character
        board[row][col] = '*';       // Mark the cell as visited

        // Explore in all four directions
        bool found = solve(board, word, idx + 1, row - 1, col, m, n) || // Up
                     solve(board, word, idx + 1, row + 1, col, m, n) || // Down
                     solve(board, word, idx + 1, row, col - 1, m, n) || // Left
                     solve(board, word, idx + 1, row, col + 1, m, n);   // Right

        board[row][col] = temp; // Restore the cell
        return found;
    }
};
