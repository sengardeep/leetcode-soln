class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=graph.size();
        temp.push_back(0);
        function<void(int)> dfs = [&](int node){
            if(node==n-1){
                ans.push_back(temp);
                return;
            }
            for(auto nb : graph[node]){
                temp.push_back(nb);
                dfs(nb);
                temp.pop_back();
            }
            return;
        };
        dfs(0);
        return ans;
    }
};