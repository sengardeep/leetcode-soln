class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=points.size();
        pq.push({0,0}); //dist,idx
        vector<int> vis(n,0);
        int ans=0;
        while(!pq.empty()){
            auto [d,p] = pq.top();
            pq.pop();
            if(vis[p]) continue;
            vis[p]=1;
            ans+=d;
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                int x=points[p][0],y=points[p][1];
                int a=points[i][0],b=points[i][1];
                int dist = abs(x-a)+abs(y-b);
                pq.push({dist,i});
            }
        }
        return ans;
    }
};