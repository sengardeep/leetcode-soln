class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if((m+n-1)%2) return 0;
        vector<vector<vector<int>>> dp(100,vector<vector<int>>(100,vector<int>(200,-1)));
        function<int(int,int,int)> dfs = [&](int i,int j,int bal){
            if(i>=m || j>=n) return 0;
            bal += grid[i][j]=='(';
            bal -= grid[i][j]==')';
            if(bal<0) return 0;
            if(i==m-1 && j==n-1){
                if(bal) return 0;
                else return 1;
            } 
            if(dp[i][j][bal]!=-1) return dp[i][j][bal];
            return dp[i][j][bal]=max(dfs(i+1,j,bal),dfs(i,j+1,bal));
        };
        return dfs(0,0,0);
    }
};