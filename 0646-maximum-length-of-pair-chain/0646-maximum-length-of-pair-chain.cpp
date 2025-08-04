class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<vector<int>> dp(n,vector<int>(2,1));

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]) dp[i][1]=max(dp[i][1],dp[j][1]+1);
                dp[i][0]=max({dp[i][0],dp[j][1],dp[j][0]});
            }
        }

        return max(dp[n-1][1],dp[n-1][0]);
    }
};