class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]); // Path compression
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        // Union by rank
        if (rank[a] < rank[b]) {
            parent[a] = b;
        } else if (rank[a] > rank[b]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }

    bool connected(int a, int b) { return find(a) == find(b); }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU ds(edges.size()+1);
        for(auto v : edges){
            if(ds.connected(v[0],v[1])) return v;
            ds.unite(v[0],v[1]);
        }
        return {};
    }
};