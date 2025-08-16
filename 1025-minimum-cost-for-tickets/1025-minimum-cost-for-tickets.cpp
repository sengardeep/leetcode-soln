class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return helper(days, costs, 0, n, dp);
    }

private:
    int helper(vector<int>& days, vector<int>& costs, int index, int n,
               vector<int>& dp) {
        if (index == n)
            return 0;

        if (dp[index] != -1)
            return dp[index];
        // 1-Day
        int ans = costs[0] + helper(days, costs, index + 1, n, dp);
        // 7-Days
        int num = days[index] + 6;
        int idx = upper_bound(days.begin(), days.end(), num) - days.begin();
        ans = min(ans, costs[1] + helper(days, costs, idx, n, dp));

        // 30-Days
        num = days[index] + 29;
        idx = upper_bound(days.begin(), days.end(), num) - days.begin();
        ans = min(ans, costs[2] + helper(days, costs, idx, n, dp));

        return dp[index] = ans;
    }
};