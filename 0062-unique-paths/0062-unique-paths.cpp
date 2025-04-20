class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //right
                if(j<n-1)
                {
                    dp[i][j+1] += dp[i][j];
                }
                //down
                if(i<m-1)
                {
                    dp[i+1][j] += dp[i][j];
                }
            }
        }

        return dp[m-1][n-1];
    }
};