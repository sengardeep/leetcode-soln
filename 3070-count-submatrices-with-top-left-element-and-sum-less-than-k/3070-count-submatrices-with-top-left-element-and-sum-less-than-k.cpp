class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++) for(int j=1;j<n;j++) grid[i][j]+=grid[i][j-1];
        for(int j=0;j<n;j++) {
            if(grid[0][j]>k) break;
            int sum=0;
            for(int i=0;i<m;i++){
                sum+=grid[i][j];
                if(sum<=k) ans++;
                else break;
            }
        }
        return ans;
    }
};