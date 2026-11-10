class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 3; k++) {
                int j = i - k;
                if (j < 0)
                    break;
                dp[i] = min(dp[i], costs[i-1] + k * k + dp[j]);
            }
        }
        return dp[n];
    }
};