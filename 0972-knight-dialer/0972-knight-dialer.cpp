class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> choice = {{4, 6},    {6, 8}, {7, 9},    {4, 8},
                                      {0, 3, 9}, {},     {0, 1, 7}, {2, 6},
                                      {1, 3},    {2, 4}};

        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        // dp[i][j] : number of combinations of length i ending at j
        for (int i = 0; i < 10; i++)
            dp[1][i] = 1;
        int mod = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                int x = dp[i - 1][j];
                for (auto it : choice[j]) {
                    dp[i][it] = (dp[i][it] + x) % mod;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 10; i++)
            ans = (ans + dp[n][i]) % mod;

        return ans;
    }
};