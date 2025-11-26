class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum = 0;
        for(auto it : nums) sum+=it;
        if(sum%2) return 0;
        vector<int> dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++) for(int j=sum;j>=nums[i];j--)  dp[j]=max(dp[j],dp[j-nums[i]]);
        int target=sum/2;
        return dp[target];
    }
};