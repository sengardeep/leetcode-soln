class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if(matrix[0][0]==1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) continue;
                if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
                if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};