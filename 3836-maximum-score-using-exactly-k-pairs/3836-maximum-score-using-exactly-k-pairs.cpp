class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(m+1,vector<long long>(k+1,-1e18)));
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int p=1;p<=k;p++){
                    dp[i][j][p] = max({
                    dp[i-1][j][p],  
                    dp[i][j-1][p],  
                    dp[i-1][j-1][p-1] + nums1[i-1] * 1LL * nums2[j-1]
                });
                }
            }
        }

        return dp[n][m][k];
    }
};