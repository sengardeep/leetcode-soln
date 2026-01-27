class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto vec : edges){
            int u=vec[0],v=vec[1],w=vec[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        vector<int> ans(n,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(n,0);
        while(!pq.empty()){
            auto [w,node]=pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            ans[node]=w;
            for(auto [child,weight] : adj[node]){
                if(!vis[child]){
                    pq.push({weight+w,child});
                }
            }
        }
        return ans[n-1];
    }
};