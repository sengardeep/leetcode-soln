class Solution {
public:
    int numberOfWays(int n, int x) {
        // if(x==1) return (n+1)/2;

        vector<int> powers;
        for(int i=1;i<=n;i++) {
            int num = binpow(i,x);
            if(num > n) break;
            powers.push_back(num);
        }

        int m=powers.size();
        vector<vector<int>> dp(m,vector<int>(n+1,0));
        dp[0][0]=1; //dp[i][j] : no. of ways to make sum j till i
        int MOD = 1e9+7;
        dp[0][powers[0]]=1;
        for(int i=1;i<m;i++){
            for(int j=0;j<=n;j++){
                if(j<powers[i]) dp[i][j]=dp[i-1][j];
                else dp[i][j] = (dp[i-1][j] + dp[i-1][j-powers[i]])%MOD;
            }
        }
        return dp[m-1][n];
    }
private:
    int binpow(int base,int exp){
        int ans=1;
        while(exp){
            if(exp&1) ans = ans*base;
            base = base*base;
            exp>>=1;
        }
        return ans;
    }
};