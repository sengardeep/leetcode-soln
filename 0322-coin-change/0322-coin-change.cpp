class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,INT_MAX));
        //dp[i][j] : min coins needed till i index to make j
        for(int i=0;i<n;i++) dp[i][0]=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0){
                if(j>=coins[i] && dp[i][j-coins[i]]!=INT_MAX)
                dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i]]);
                }
                else{
                    if(j>=coins[i])
                    {
                        if(dp[i][j-coins[i]]!=INT_MAX)
                            dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i]]);
                        if(dp[i-1][j-coins[i]]!=INT_MAX)
                            dp[i][j]=min(dp[i][j],1+dp[i-1][j-coins[i]]);
                        dp[i][j]=min(dp[i][j],dp[i-1][j]);
                    }

                    else if(j<coins[i]) dp[i][j]=dp[i-1][j];
                }
            }
        }
        for(auto it : dp[n-1]) cout<<it<<" ";
        return (dp[n-1][amount]==INT_MAX)?-1:dp[n-1][amount];
    }
};