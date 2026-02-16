class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
        dp[1][1]=nums[0];
        for(int i=2;i<=n;i++){
            if(colors[i-1]==colors[i-2]){
                dp[i][1]=dp[i-1][0]+nums[i-1];
                dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
            }else{
                dp[i][1]=max(dp[i-1][1],dp[i-1][0])+nums[i-1];
                dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
            }
        }
        return max(dp[n][1],dp[n][0]);
    }
};