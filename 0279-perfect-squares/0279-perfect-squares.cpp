class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(isPerfectSquare(i)) dp[i]=1;
            else{
                for(int j=1;j<=i/2;j++){
                    dp[i]=min(dp[i],dp[i-j]+dp[j]);
                }
            }
        }
        return dp[n];
    }
private:
    bool isPerfectSquare(int n){
        int s=sqrt(n);
        return (s*s==n);
    }
};