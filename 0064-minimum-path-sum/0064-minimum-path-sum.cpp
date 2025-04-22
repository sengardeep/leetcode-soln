class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return helper(grid,dp,0,0,m,n);
    }
private:
    int helper(vector<vector<int>> &grid,vector<vector<int>> &dp,int row,int col,int m,int n)
    {
        if(row==m-1 && col==n-1) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];

        int right=INT_MAX;
        if(col<n-1) right=grid[row][col]+helper(grid,dp,row,col+1,m,n);
        int down=INT_MAX;
        if(row<m-1) down=grid[row][col]+helper(grid,dp,row+1,col,m,n);

        return dp[row][col]=min(right,down);
    }
};