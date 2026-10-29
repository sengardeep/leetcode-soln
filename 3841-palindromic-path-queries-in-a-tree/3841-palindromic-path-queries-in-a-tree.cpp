class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        // Segment tree, LCA (Binary Lifting), XOR checks palindrome, Euler Tour
        vector<int> adj[n];
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // DFS to calculate parent, tin, tout and euler tour
        vector<int> tin(n), tout(n), euler, depth(n), parent(n, -1);
        int LOG = ceil(log2(n)) + 1;
        vector<vector<int>> up(n, vector<int>(LOG, 0));
        parent[0] = 0;
        depth[0] = 0;
        int timer = 0;
        function<void(int)> dfs = [&](int node) {
            tin[node] = timer;
            euler.push_back((1 << (s[node] - 'a')));
            timer++;

            up[node][0] = parent[node];
            for (int j = 1; j < LOG; j++) {
                up[node][j] = up[up[node][j - 1]][j - 1];
            }

            for (auto child : adj[node]) {
                if (parent[child] == -1) {
                    parent[child] = node;
                    depth[child] = depth[node] + 1;
                    dfs(child);
                }
            }
            tout[node] = timer;
            euler.push_back((1 << (s[node] - 'a')));
            timer++;
            return;
        };
        dfs(0);
        // Calculate LCA
        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) {
                swap(u, v);
            }
            int diff = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++) {
                if ((diff >> j) & 1) {
                    u = up[u][j];
                }
            }
            if (u == v)
                return u;
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }
            return up[u][0];
        };
        // Segment Tree
        int euler_sz = euler.size();
        vector<int> st(4 * euler_sz);
        auto merge = [](int a, int b) { return a ^ b; };
        function<void(int, int, int)> build = [&](int start, int end,
                                                  int index) -> void {
            if (start == end) {
                st[index] = euler[start];
                return;
            }
            int mid = (start + end) / 2;
            build(start, mid, 2 * index);
            build(mid + 1, end, 2 * index + 1);
            st[index] = merge(st[2 * index], st[2 * index + 1]);
        };
        function<void(int, int, int, int, int)> update =
            [&](int start, int end, int index, int k, int val) -> void {
            if (start == end) {
                st[index] = val;
                return;
            }
            int mid = (start + end) / 2;
            if (k <= mid) {
                update(start, mid, 2 * index, k, val);
            } else {
                update(mid + 1, end, 2 * index + 1, k, val);
            }
            st[index] = merge(st[2 * index], st[2 * index + 1]);
        };
        function<int(int, int, int, int, int)> query =
            [&](int start, int end, int index, int l, int r) -> int {
            if (start > r || end < l)
                return 0;
            if (start >= l && end <= r)
                return st[index];
            int mid = (start + end) / 2;
            int left = query(start, mid, 2 * index, l, r);
            int right = query(mid + 1, end, 2 * index + 1, l, r);
            return left ^ right;
        };
        build(0, euler_sz - 1, 1);
        vector<bool> ans;
        for (auto q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (q.find("update") != string::npos) {
                int index;
                char c;
                ss >> index >> c;
                int k = 1 << (c - 'a');
                s[index] = c;
                update(0, euler_sz - 1, 1, tin[index], k);
                update(0, euler_sz - 1, 1, tout[index], k);
            } else {
                int u, v;
                ss >> u >> v;
                int xr = query(0, euler_sz - 1, 1, 0, tin[u]) ^
                         query(0, euler_sz - 1, 1, 0, tin[v]) ^
                         (1 << (s[lca(u, v)] - 'a'));
                if (xr & (xr - 1))
                    ans.push_back(0);
                else
                    ans.push_back(1);
            }
        }
        return ans;
    }
};