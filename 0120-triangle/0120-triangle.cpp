class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m - 1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, helper(triangle, dp, m - 1, i));
        }
        return ans;
    }

   private:
    int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int row,
               int col) {
        if (row == 0) return triangle[row][col];

        if (dp[row][col] != -1) return dp[row][col];
        // Go for all three directions

        int up = INT_MAX;
        if (col != triangle[row].size() - 1)
            up = helper(triangle, dp, row - 1, col);
        int upper_left = INT_MAX;
        if (col != 0) upper_left = helper(triangle, dp, row - 1, col - 1);

        return dp[row][col] = triangle[row][col] + min(up, upper_left);
    }
};
