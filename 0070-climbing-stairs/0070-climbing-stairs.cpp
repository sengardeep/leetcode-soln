class Solution {
public:
    int climbStairs(int n) {
       vector<int> dp(n+1,-1);
       return helper(n,dp); 
    }
private:
    int helper(int n,vector<int> &dp)
    {
        if(n<=2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n]=helper(n-2,dp)+helper(n-1,dp);
    }
};