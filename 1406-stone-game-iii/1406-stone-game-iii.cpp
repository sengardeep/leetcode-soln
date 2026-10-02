class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--){
            int ans = -1e9,sum=0;
            for(int k=1;i+k<=n && k<=3;k++){
                sum += stoneValue[i+k-1];
                ans = max(ans,sum-dp[i+k]);
            }
            dp[i]=ans;
        }
        return dp[0]==0 ? "Tie" : (dp[0]<0 ? "Bob" : "Alice");
    }
};