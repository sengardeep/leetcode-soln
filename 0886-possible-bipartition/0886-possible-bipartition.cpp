class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, -1);
        vector<int> adj[n + 1];
        for (auto v : dislikes) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        queue<int> q;
        auto bfs = [&](int src) {
            q.push(src);
            int c = 0;
            color[src] = c;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto nb : adj[node]) {
                    if (color[nb] == -1) {
                        color[nb] = color[node] ^ 1;
                        q.push(nb);
                    } else if (color[nb] != (color[node] ^ 1))
                        return 0;
                }
            }
            return 1;
        };
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1 && !bfs(i))
                return 0;
        }
        return 1;
    }
};