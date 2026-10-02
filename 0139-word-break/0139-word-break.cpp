class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++){
            for(auto word : wordDict){
                int l = word.size();
                if(i+l>n) continue;
                string curr = s.substr(i,l);
                if(curr==word){
                    if(i==0 || dp[i-1]==1) dp[i+l-1]=1; 
                }
            }
        }
        return dp[n-1];
    }
};