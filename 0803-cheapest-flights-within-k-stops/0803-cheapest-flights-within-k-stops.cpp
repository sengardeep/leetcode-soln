class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        // Shortest path algorithm making priority of number of stops
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<tuple<int, int, int>> q; //(stops,node,distance)
        q.push({0, src, 0});
        vector<int> ans(n, INT_MAX);
        ans[src] = 0;
        // vector<bool> visited(n, 0);
        while (!q.empty()) {
            int stops = get<0>(q.front());
            int node = get<1>(q.front());
            int dist = get<2>(q.front());
            // if (node != dst)
            //     visited[node] = true;
                q.pop();
            for (int i = 0; i < adj[node].size(); i++) {
                int nbr = adj[node][i].first;
                int d = adj[node][i].second;

                if ((nbr == dst && stops > k) || d + dist >= ans[nbr])
                    continue;

                ans[nbr] = min(ans[nbr], d + dist);
                q.push({stops + 1, nbr, ans[nbr]});
            }
        }

        if (ans[dst] == INT_MAX)
            return -1;
        return ans[dst];
    }
};