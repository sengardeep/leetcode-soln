class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e9);
        dp[0]=0;
        for(long long i=0;i<=amount;i++){
            for(long long c : coins){
                if((i+c)>amount) continue;
                dp[i+c]=min(dp[i+c],dp[i]+1);
            }
        }
        return dp[amount]==1e9?-1:dp[amount];
    }
};