class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> deg(n);
        for (auto v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            deg[v[0]]++;
            deg[v[1]]++;
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (deg[i] == 1)
                q.push(i);
        vector<int> vis(n, 0);
        while (!q.empty()) {
            ans.clear();
            int s = q.size();
            while (s--) {
                int node = q.front();
                q.pop();
                if (vis[node])
                    continue;
                ans.push_back(node);
                vis[node] = 1;
                for (auto nb : adj[node]) {
                    if (!vis[nb]) {
                        deg[nb]--;
                        if (deg[nb] == 1)
                            q.push(nb);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(0);
        return ans;
    }
};