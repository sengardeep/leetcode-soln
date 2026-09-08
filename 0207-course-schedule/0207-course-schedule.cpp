class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        vector<int> adj[numCourses];
        for (auto v : prerequisites) {
            indeg[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto neighb : adj[node]){
                indeg[neighb]--;
                if(indeg[neighb]==0){
                    q.push(neighb);
                }
            }
        }
        for(auto x : indeg) if(x) return 0;
        return 1;
    }
};