class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(
            m, vector<int>(n, 0)); // dp[i][j]:maximum area square till (i,j)

        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[0][i] = (matrix[0][i] - '0');
            ans = max(ans, dp[0][i]);
        }
        for (int i = 0; i < m; i++) {
            dp[i][0] = (matrix[i][0] - '0');
            ans = max(ans, dp[i][0]);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int curr = matrix[i][j] - '0';
                if(curr != 0)
                dp[i][j] =
                    min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + curr;
                ans = max(ans, dp[i][j]);
            }
        }

        return ans * ans;
    }
};