class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int count=0;
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(adj[i][j])
                {
                    count++;
                    dfs(adj,i);
                }
            }
        }
        return count;
    }
  private:
    void dfs(vector<vector<int>>& adj,int node)
    {
        adj[node][node]=0;
        for(int i=0;i<adj[node].size();i++)
        {
            if(adj[node][i]==0) continue;
            adj[node][i]=0;
            adj[i][node]=0;
            dfs(adj,i);
        }
    }
};