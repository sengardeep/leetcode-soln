class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return helper(arr, n, k, dp, 1, 0, k);
    }

private:
    int helper(vector<int>& arr, int n, int k, vector<vector<vector<int>>>& dp,
               int buy, int idx, int count) {
        if (idx == n || count == 0)
            return 0;

        if (dp[idx][buy][count] != -1)
            return dp[idx][buy][count];

        int profit = 0;
        if (buy)
            profit = max((-arr[idx] + helper(arr, n, k, dp, 0, idx + 1, count)),
                         (helper(arr, n, k, dp, 1, idx + 1, count)));
        else
            profit =
                max((arr[idx] + helper(arr, n, k, dp, 1, idx + 1, count - 1)),
                    (helper(arr, n, k, dp, 0, idx + 1, count)));

        return dp[idx][buy][count] = profit;
    }
};