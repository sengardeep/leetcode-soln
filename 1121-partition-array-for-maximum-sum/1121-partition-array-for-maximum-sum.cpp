class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            int maxi = 0;
            for (int j = 0; j < k && i - j >= 0; j++) {
                maxi = max(maxi, arr[i - j]); 
                dp[i] = max(dp[i], (i - j > 0 ? dp[i - j - 1] : 0) + maxi * (j + 1));
            }
        }

        return dp[n - 1];
    }
};
