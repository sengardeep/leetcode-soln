class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> inDegree(numCourses,0);
        for(auto it : prerequisites)
        {
        adj[it[1]].push_back(it[0]);
        inDegree[it[0]]++;
        }
        //Kahn's Algo (As we've to check if it forms a Direct Acyclic Graph(DAG))
        stack<int> st;
        for(int i=0;i<numCourses;i++) if(inDegree[i]==0) st.push(i);
        int count=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            count++;
            for(int i=0;i<adj[node].size();i++)
            {
                int neighbour=adj[node][i];
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0) st.push(neighbour);
            }
        }

        return (count==numCourses);
    }
};