class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int len=1,idx=0;
        string ans="";
        function<int(int,int)> f = [&](int i,int j){
            if(i>=j) return 1;
            if(dp[i][j]!=-1) return dp[i][j];
            if(s[i]==s[j] && f(i+1,j-1)){
                int l = j-i+1;
                if(l>len){
                    len=l;
                    idx=i;
                }
                return dp[i][j]=1;
            }
            f(i+1,j);
            f(i,j-1);
            return dp[i][j] = 0;
        };
        f(0,n-1);
        ans = s.substr(idx,len);
        return ans;
    }
};