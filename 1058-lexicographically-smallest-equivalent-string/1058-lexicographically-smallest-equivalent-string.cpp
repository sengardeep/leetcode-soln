class DSU {
public:
    unordered_map<char, char> parent;

    // Make a set with the character itself as parent
    void makeSet(string& chars) {
        for (char c : chars) {
            parent[c] = c;
        }
    }

    // Find with path compression
    char find(char c) {
        if (parent[c] != c)
            parent[c] = find(parent[c]);
        return parent[c];
    }

    // Union by lexicographically smallest character
    void unite(char a, char b) {
        char pa = find(a);
        char pb = find(b);
        if (pa == pb) return;

        // Set the smaller character as parent
        if (pa < pb)
            parent[pb] = pa;
        else
            parent[pa] = pb;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU ds;
        
        ds.makeSet(baseStr);
        ds.makeSet(s1);
        ds.makeSet(s2);

        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            ds.unite(s1[i],s2[i]);
        }

        string ans;
        for(auto it : baseStr) ans += ds.find(it);

        return ans;
    }
};