class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));

        // Base Case: amount 0 can always be made with 0 coins
        for (int i = 0; i < n; ++i) dp[i][0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                // Option 1: don't take the coin
                if (i > 0)
                    dp[i][j] = dp[i-1][j];

                // Option 2: take the coin if it's not more than j
                if (j >= coins[i] && dp[i][j - coins[i]] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i]]);
                }
            }
        }

        return dp[n-1][amount] == INT_MAX ? -1 : dp[n-1][amount];
    }
};
