class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size())
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[n][m] = 1;
        for (int i = n - 1; i >= 0; i--) {
            dp[i][m] = dp[i + 1][m] && (s1[i] == s3[i + m]);
        }
        for (int j = m - 1; j >= 0; j--) {
            dp[n][j] = dp[n][j + 1] && (s2[j] == s3[n + j]);
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s3[i + j] && s2[j] == s3[i + j]) {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                } else if (s1[i] == s3[i + j]) {
                    dp[i][j] = dp[i + 1][j];
                } else if (s2[j] == s3[i + j]) {
                    dp[i][j] = dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};