class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        map<int,set<int>> mp;
        vector<int> adj[numCourses];
        for(auto v : prerequisites) adj[v[0]].push_back(v[1]);
        function<void(int)> dfs=[&](int node){
            for(auto neigh : adj[node]){
                dfs(neigh);
                for(auto x : mp[neigh]) mp[node].insert(x);
            }
            mp[node].insert(node);
            return;
        };
        for(int i=0;i<numCourses;i++){
            if(mp.count(i)==0) dfs(i);
        }
        vector<bool> ans;
        for(auto v : queries){
            if(mp[v[0]].count(v[1])) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};