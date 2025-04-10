class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Apply Dijkstra along with a vector (ways) that will store the number
        // of ways to reach to every node

        int MOD = 1e9 + 7;
        vector<long long> ways(n, 0);
        ways[0]=1;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<pair<long long, long long>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long d = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for (long long i = 0; i < adj[node].size(); i++) {
                long long nbr = adj[node][i].first, wt = adj[node][i].second;
                if (wt + d > dist[nbr])
                    continue;
                else if (wt + d == dist[nbr])
                    ways[nbr] = (ways[nbr] + ways[node]) % MOD;
                else {
                    if(dist[nbr] != LLONG_MAX) ways[nbr]=0;
                    ways[nbr] = (ways[nbr] + ways[node]) % MOD;
                    dist[nbr] = min(dist[nbr], wt + d);
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        // for(auto it : ways) cout<<it<<" ";
        return (int)ways[n - 1];
    }
};