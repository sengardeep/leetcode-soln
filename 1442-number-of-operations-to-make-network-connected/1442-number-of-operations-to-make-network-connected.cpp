class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n - 1 > connections.size())
            return -1;
        int m = connections.size();
        int ans = 0;
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (int i = 0; i < m; i++) {
            int u = connections[i][0], v = connections[i][1];
            unionByRank(u, v);
        }
        int u = 0;
        for (int i = 1; i < n; i++) {
            if (check(u, i))
                continue;
            ans++;
            unionByRank(u, i);
        }
        return ans;
    }

private:
    vector<int> parent, rank;
    bool check(int u, int v) { return findUpar(u) == findUpar(v); }
    void unionByRank(int u, int v) {
        int pu = findUpar(u); // Find the ultimate parent of u
        int pv = findUpar(v); // Find the ultimate parent of v
        if (pu == pv)
            return; // If they are already in the same set, do nothing
        if (rank[pu] < rank[pv])
            parent[pu] = pv; // Make v the parent of u
        else if (rank[pu] > rank[pv])
            parent[pv] = pu; // Make u the parent of v
        else // If ranks are equal, make one as root and increase its rank by 1
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    int findUpar(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findUpar(parent[u]); // Path compression
    }
};