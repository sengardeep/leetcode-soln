class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> parent(n*n, 0);
        iota(begin(parent), end(parent), 0);
        vector<int> size(n*n, 1);

        function<int(int)> find = [&](int x){
            if(x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b){
            int pA = find(a);
            int pB = find(b);
            if (pA != pB) {
                if (size[pA] < size[pB]) {
                    parent[pA] = pB;
                    size[pB] += size[pA];
                } else {
                    parent[pB] = pA;
                    size[pA] += size[pB];
                }
            }
        };
        auto check = [&](int a, int b){
            if(find(a) == find(b)) return 1;
            return 0;
        };
        vector<vector<int>> vis(n,vector<int>(n,0));
        pair<int,int> dir[4] = {{0,-1},{0,1},{-1,0},{1,0}};
        int ans=0,count=0;
        function<void(int,int)> dfs = [&](int i,int j){
            vis[i][j]=1;
            count++;
            for(auto [x,y] : dir){
                int r=i+x,c=j+y;
                if(r<0 || c<0 || r>=n || c>=n || vis[r][c]==1 || grid[r][c]==0) continue;
                int idx1=i*n+j, idx2=r*n+c;
                unite(idx1,idx2); 
                dfs(r,c);
            }
            return;
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count=0;
                    dfs(i,j);
                    ans=max(ans,count);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> st;
                    for(auto [x,y] : dir){
                        int r=i+x,c=j+y;
                        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]==0) continue;
                        int p=find(r*n+c);
                        st.insert(p);
                    }
                    int res=1;
                    for(auto x : st) res+=size[x];
                    ans=max(ans,res);
                }
            }
        }
        return ans;
    }
};