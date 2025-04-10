class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Apply Dijkstra and find max of all
        vector<pair<int,int>> adj[n+1];
        for(auto it : times) adj[it[0]].push_back({it[1],it[2]});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                int nbr=adj[node][i].first,wt=adj[node][i].second;
                if(d+wt >= dist[nbr]) continue;

                dist[nbr]=min(dist[nbr],d+wt);
                pq.push({dist[nbr],nbr});
            }
        }

        int ans=*max_element(dist.begin()+1,dist.end());
        return (ans!=INT_MAX)?ans:-1;
    }
};