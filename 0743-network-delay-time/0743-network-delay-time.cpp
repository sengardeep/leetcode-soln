class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto v : times) adj[v[0]].push_back({v[1],v[2]});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> time(n+1,1e9);
        pq.push({0,k});
        while(!pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();
            // cout<<node<<endl;
            if(time[node] != 1e9) continue;
            time[node]=wt;
            for(auto [nb,w] : adj[node]){
                pq.push({w+wt,nb});
            }
        }
        int mx = *max_element(begin(time)+1,end(time));
        return (mx==1e9)?-1:mx;
    }
};