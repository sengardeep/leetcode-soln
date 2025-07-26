class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        cost.push_back(0);
        return helper(cost,dp,n);
    }
private:
    int helper(vector<int>& cost,vector<int>& dp,int idx){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];

        dp[idx]=cost[idx]+min(helper(cost,dp,idx-1),helper(cost,dp,idx-2));

        return dp[idx];
    }
};