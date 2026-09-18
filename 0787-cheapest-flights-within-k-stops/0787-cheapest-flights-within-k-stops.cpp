class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];
        for (auto v : flights)
            adj[v[0]].push_back({v[1], v[2]});
        using T = tuple<int, int, int>; // stops,node,dist
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<T> q;
        q.push({0, src, 0});
        while (!q.empty()) {
            auto [stops, node, d] = q.front();
            q.pop();
            for (auto [nb, wt] : adj[node]) {
                if (stops >= k && nb != dst)
                    continue;
                if (dist[nb] > d + wt) {
                    dist[nb] = d + wt;
                    q.push({stops + 1, nb, d + wt});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};