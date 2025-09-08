class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9+7;
        vector<int> dp(n+1,-1);
        function<int(int)> f = [&](int i)->int{
            if(i==1) return 1;
            if(i==2) return 2;
            if(i==3) return 5;
            if(dp[i] != -1) return dp[i];

            return dp[i]=((f(i-1)*1LL*2)%mod+f(i-3))%mod;
        };
        return f(n);
    }
};