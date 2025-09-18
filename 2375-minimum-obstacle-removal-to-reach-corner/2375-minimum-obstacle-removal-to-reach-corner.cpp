#define pii pair<int,int>
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        auto check = [&](int r,int c)->bool{
            return (r>=0&&r<m && c>=0&&c<n);
        };
        vector<pair<int,int>> dir{{-1,0},{0,-1},{1,0},{0,1}};
        priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq; //{obstacle,{x,y}}
        map<pii,int> ans;
        ans[{0,0}]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            auto [d,p] = pq.top(); pq.pop();
            auto [r,c] = p;
            if(ans.count({r,c}) && ans[{r,c}] > d) continue;
            for(int i=0;i<4;i++){
                int row = r+dir[i].first,col=c+dir[i].second;
                if(check(row,col)==false) continue;
                if(!ans.count({row,col}))
                {
                 ans[{row,col}]=d+grid[row][col];
                 pq.push({ans[{row,col}],{row,col}});
                }
                else if(ans[{row,col}] > d+grid[row][col]){
                    ans[{row,col}]=d+grid[row][col];
                    pq.push({ans[{row,col}],{row,col}});
                }
            }
        }
        return ans[{m-1,n-1}];
    }
};