class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> row(m,0),col(n,0);

        for(int i=0;i<m;i++){
            row[i]=accumulate(grid[i].begin(),grid[i].end(),0);
        }

        for(int j=0;j<n;j++)
        {
            int sum=0;
            for(int i=0;i<m;i++) sum+=grid[i][j];
            col[j]=sum;
        }

        long long ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans += ((row[i]-1)*(col[j]-1));
                }
            }
        }

        return ans;
    }
};