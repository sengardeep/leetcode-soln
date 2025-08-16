class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n]=0;

        for(int i=n-1;i>=0;i--)
        {
            //1-Day
            dp[i]=min(dp[i],costs[0]+dp[i+1]);
            //7-Days
            int num = days[i] + 6;
            int idx = upper_bound(days.begin(), days.end(), num) - days.begin();
            dp[i]=min(dp[i],costs[1]+dp[idx]);
            //30-Days
            num = days[i] + 29;
            idx = upper_bound(days.begin(), days.end(), num) - days.begin();
            dp[i]=min(dp[i],costs[2]+dp[idx]);
        }
        return dp[0];
    }
};