class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<pair<int,int>> adj[n];
        for(auto e : edges) adj[e[0]].push_back({e[1],e[2]});
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<vector<int>> min_dist(n, vector<int>(k + 1, 1e9));
        pq.push({0,0,1}); 
        min_dist[0][1] = 0;
        vector<int> ans(n,1e9);
        ans[0]=0;
        while(!pq.empty()){
            auto [d,node,count] = pq.top();
            pq.pop();
            if(d>min_dist[node][count]) continue;
            if(node==n-1) return d;
            for(auto [nb,wt] : adj[node]){
                int cnt = 1;
                if(labels[node] == labels[nb]) cnt = count+1;
                if(cnt>k) continue;
                if(min_dist[nb][cnt]>d+wt){
                    min_dist[nb][cnt]=d+wt;
                    pq.push({d+wt,nb,cnt});
                }
            }
        }
        return -1;
    }
};