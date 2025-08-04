class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        //dp[i] : maximum product possible for i
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=max({dp[i],dp[i-j]*j,dp[i-j]*dp[j],(i-j)*j});
            }
        }
        return dp[n];
    }
};