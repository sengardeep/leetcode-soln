class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        function<int(int,int)> f = [&](int index,int k){
            if(index==n && k==d) return 0;
            if((index==n && k!=d)||(k==d)) return 1000000000;
            if(dp[index][k] != -1) return dp[index][k];
            int rem = d-k;
            int mx=0;
            int ans=1e9;
            for(int i=index;i<=n-rem;i++){
                mx = max(mx,jobDifficulty[i]);
                ans = min(ans,mx+f(i+1,k+1));
            }
            return dp[index][k] = ans;
        };
        int ans=f(0,0);
        if(ans==1e9) ans=-1;
        return ans;
    }
};