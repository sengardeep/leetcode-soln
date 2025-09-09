class TreeAncestor {
private:
    vector<vector<int>> dp;

public:
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(n, vector<int>(17, -1));
        int root = -1;
        for (int i = 0; i < n; i++)
            if (parent[i] == -1)
                root = i;
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            adj[i].push_back(parent[i]);
            if (parent[i] != -1) {
                adj[parent[i]].push_back(i);
            }
        }

        // for(auto it : adj) {
        //     for(auto x : it) cout<<x<<" ";
        //     cout<<endl;
        // }

        function<void(int, int)> dfs = [&](int node, int par) -> void {
            dp[node][0] = par;
            for (int j = 1; j <= 16; j++) {
                if (dp[node][j - 1] != -1)
                    dp[node][j] = dp[dp[node][j - 1]][j - 1];
            }
            for (auto child : adj[node]) {
                if (child == par)
                    continue;
                dfs(child, node);
            }
        };

        dfs(root, -1);
        // for (int i = n - 1; i >= 0; i--)
        //     for (int j = 1; j <= 16; j++) {
        //         if (dp[i][j - 1] != -1)
        //             dp[i][j] = dp[dp[i][j - 1]][j - 1];
        //     }

        // for(auto it : dp)
        // {
        // for(auto x : it) cout<<x<<" ";
        // cout<<endl;
        // }
    }

    int getKthAncestor(int node, int k) {
        int cnt = 0;
        while (k && node != -1) {
            if (k & 1) {
                node = dp[node][cnt];
            }
            k >>= 1;
            cnt++;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */