class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix;  // dp[0][i] = matrix[0][i] already

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int up = dp[i - 1][j];
                int upper_left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int upper_right = (j < n - 1) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({up, upper_left, upper_right});
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
