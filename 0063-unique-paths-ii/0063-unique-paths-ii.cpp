class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(matrix, dp, m - 1, n - 1);
    }

   private:
    int helper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int row,
               int col) {
        if (row < 0 || col < 0 || matrix[row][col] == 1) return 0;
        if (row == 0 && col == 0) return 1;
        if (dp[row][col] != -1) return dp[row][col];
        // Go for both directions (up and left)
        int left = helper(matrix, dp, row - 1, col);
        int up = helper(matrix, dp, row, col - 1);

        return dp[row][col] = left + up;
    }
};