class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using pii = pair<int,int>;
        vector<vector<pii>> adj(n);
        for(auto it : flights) adj[it[0]].push_back({it[1],it[2]});
        using T = tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({0,src,0}); //{cost,node,k}
        vector<long long> ans(n,1e18);
        ans[src]=0;
        while(!pq.empty()){
            auto [x,node,c] = pq.top(); pq.pop();
            // if(ans[node] < c) continue;
            if(x>k) continue;
            for(auto [child,w] : adj[node]){
                if(ans[child] > w+c){
                    ans[child]=w+c;
                    pq.push({x+1,child,ans[child]});
                }
            }
        }
        // for(auto it : ans) cout<<it<<" ";
        return (ans[dst]==1e18)?-1:ans[dst];
    }
};