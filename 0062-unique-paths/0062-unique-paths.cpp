class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(dp, m - 1, n - 1);
    }

   private:
    int helper(vector<vector<int>>& dp, int row, int col) {
        if (row == 0 && col == 0) return dp[row][col] = 1;
        if (dp[row][col] != -1) return dp[row][col];
        // Go for both directions (up and left)
        int left = 0, up = 0;
        if (row > 0) left = helper(dp, row - 1, col);
        if (col > 0) up = helper(dp, row, col - 1);

        return dp[row][col] = left + up;
    }
};