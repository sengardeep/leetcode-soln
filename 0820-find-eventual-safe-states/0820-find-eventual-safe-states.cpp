class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //Reverse The graph and find TOPOLOGICAL SORT
        vector<int> adj[graph.size()];
        vector<int> inDegree(graph.size(),0);
        queue<int> q;
        for(int i=0;i<graph.size();i++)
        {
            if(graph[i].empty()) q.push(i);
            for(auto it : graph[i])
            {
                adj[it].push_back(i);
            }
        }
        for(auto it  :  adj)
        for(auto x : it) inDegree[x]++;
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                inDegree[adj[node][i]]--;
                if(inDegree[adj[node][i]]==0)
                q.push(adj[node][i]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};