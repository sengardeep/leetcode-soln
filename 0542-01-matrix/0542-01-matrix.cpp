class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        vector<int> dir[]={{0,1},{1,0},{0,-1},{-1,0}};
        int count=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=row+dir[i][0],c=col+dir[i][1];
                    if(r<0 || r>=m || c<0 || c>=n) continue;

                    if(mat[r][c]==1)
                    {
                        mat[r][c]=0;
                        q.push({r,c});
                        ans[r][c]=count;
                    }
                }
            }
            count++;
        }
        return ans;
    }
};