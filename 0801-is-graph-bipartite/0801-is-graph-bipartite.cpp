class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),0);  //R->1,B->-1
        
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==0 && !BFS(graph,color,i)) return false;
        }

        return true;
        
    }
private:
    bool BFS(vector<vector<int>>&graph,vector<int> &color,int node)
    {
        queue<int> q;
        q.push(node);
        color[node]=1;
        while(!q.empty())
        {
            int node=q.front();
            int c=color[node];
            q.pop();
            for(int i=0;i<graph[node].size();i++)
            {
                int neighbour=graph[node][i];
                if(color[neighbour] == c) return false;
                if(color[neighbour] == 0)
                {
                    q.push(neighbour);
                    color[neighbour]=c*(-1);
                }
            }
        }
        return true;
    }
};