class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        string s=num2;
        const int mod=1e9+7;
        vector<vector<vector<long long>>> dp(23,vector<vector<long long>>(199,vector<long long>(2,-1)));
        function<long long(int,int,int)> helper=[&](int index,int sum,int isTight)->long long{
            if(index==s.size()) return (sum>=min_sum&&sum<=max_sum)?1:0;
            if(dp[index][sum][isTight]!=-1) return dp[index][sum][isTight];
            long long ans=0;
            for(int d=0;d<=(isTight?(s[index]-'0'):9);d++){
                ans=(ans+helper(index+1,sum+d,isTight&&(s[index]-'0'==d)))%mod;
            }
            return dp[index][sum][isTight]=ans;
        };
        int ans=helper(0,0,1);
        s=dec_one(num1);
        dp.clear();
        dp.resize(22,vector<vector<long long>>(220,vector<long long>(2,-1)));
        ans=(ans-helper(0,0,1)+mod)%mod;
        return ans;
    }
private:
    string dec_one(string s) {
    if (s == "0") return "0"; // if you never call with 0, you can drop this

    int i = (int)s.size() - 1;
    while (i >= 0 && s[i] == '0') {
        s[i] = '9';
        i--;
    }
    if (i >= 0) s[i]--;

    int pos = 0;
    while (pos + 1 < (int)s.size() && s[pos] == '0') pos++;
    return s.substr(pos);
}
};