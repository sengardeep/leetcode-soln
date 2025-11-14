class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(auto v : queries){
            int r1=v[0];
            int c1=v[1];
            int r2=v[2];
            int c2=v[3];
            for(int i=r1;i<=r2;i++) 
            {
                ans[i][c1]+=1;
                if(c2<n-1) ans[i][c2+1]-=1;
            }
        }
        for(int i=0;i<n;i++) for(int j=1;j<n;j++) ans[i][j]+=ans[i][j-1];
        return ans;
    }
};