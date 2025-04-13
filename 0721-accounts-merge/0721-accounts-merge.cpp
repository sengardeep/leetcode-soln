class DSU
{
    vector<int> parent, rank, size;
public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0); // Initialize rank to 0 for all nodes
        for (int i = 0; i < n; i++)
            parent[i] = i; // Initialize each node as its own parent
    }
    int findUpar(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = findUpar(parent[u]); // Path compression
    }
    void unionByRank(int u, int v)
    {
        int pu = findUpar(u); // Find the ultimate parent of u
        int pv = findUpar(v); // Find the ultimate parent of v
        if (pu == pv)
            return; // If they are already in the same set, do nothing
        if (rank[pu] < rank[pv])
            parent[pu] = pv; // Make v the parent of u
        else if (rank[pu] > rank[pv])
            parent[pv] = pu; // Make u the parent of v
        else                 // If ranks are equal, make one as root and increase its rank by 1
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> mp;
        DSU ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j]) == mp.end())
                mp[accounts[i][j]]=i;
                else
                ds.unionByRank(i,mp[accounts[i][j]]);
            }
        }
        vector<vector<string>> ans(n);
        for(auto it : mp)
        {
            int idx=ds.findUpar(it.second);
            ans[idx].push_back(it.first);
        }
        for(int i=0;i<n;i++) sort(ans[i].begin(),ans[i].end());
        for(int i=0;i<n;i++)
        {
            if(!ans[i].empty())
            {
                ans[i].insert(ans[i].begin(),accounts[i][0]);
            }
        }
        accounts.clear();
        for(auto it :  ans)
        {
            if(!it.empty()) accounts.push_back(it);
        }
        return accounts;
    }
};