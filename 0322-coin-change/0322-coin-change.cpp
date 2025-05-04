class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(coins, n - 1, amount, dp);
        return ans == 1e9 ? -1 : ans;
    }

private:
    int helper(vector<int>& coins, int idx, int amount,
               vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        if (idx == 0) {
            if (amount % coins[idx] == 0)
                return amount / coins[idx];
            return 1e9;
        }
        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        int take = 1e9;
        if (amount >= coins[idx])
            take = 1 + helper(coins, idx, amount - coins[idx], dp);
        int skip = helper(coins, idx - 1, amount, dp);

        return dp[idx][amount] = min(take, skip);
    }
};