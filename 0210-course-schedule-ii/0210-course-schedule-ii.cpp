class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> inDegree(numCourses,0);

        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++) if(inDegree[i]==0) q.push(i);

        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                int neighbour=adj[node][i];
                inDegree[neighbour]--;
                if(inDegree[neighbour]==0) q.push(neighbour);
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};