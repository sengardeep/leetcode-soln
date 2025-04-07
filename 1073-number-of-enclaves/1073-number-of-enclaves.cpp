class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1) DFS(grid,i,0,m,n);
            if(grid[i][n-1]==1) DFS(grid,i,n-1,m,n);
        }
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==1) DFS(grid,0,i,m,n);
            if(grid[m-1][i]==1) DFS(grid,m-1,i,m,n);
        }

        int ans=0;
        for(auto it : grid)
        for(auto x : it) ans+=(x==1);

        return ans;
    }
private:
    void DFS(vector<vector<int>>& grid,int row,int col,int m,int n)
    {
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]!=1) return;

        grid[row][col]=0;
        vector<int> dir[]={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<4;i++)
        {
            int r=row+dir[i][0],c=col+dir[i][1];
            DFS(grid,r,c,m,n);
        }
    }
};