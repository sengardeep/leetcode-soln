class Solution {
public:
    int countDigitOne(int n) {
        string s=to_string(n);
        vector<vector<vector<int>>> dp(10,vector<vector<int>>(10,vector<int>(2,-1)));
        function<int(int,int,int)> helper=[&](int index,int one,int isTight)->int{
            if(index==s.size()) return one;
            if(dp[index][one][isTight]!=-1) return dp[index][one][isTight];
            int ans=0;
            for(int d=0;d<=(isTight?(s[index]-'0'):9);d++){
                ans=(ans+helper(index+1,one+(d==1),isTight&&(s[index]-'0'==d)));
            }
            return dp[index][one][isTight]=ans;
        };
        return helper(0,0,1);
    }
};