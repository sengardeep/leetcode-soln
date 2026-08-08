class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto v : trips){
            pq.push({v[1],v[0]});
            pq.push({v[2],-v[0]});
        }
        int curr=0;
        while(!pq.empty()){
            auto x = pq.top().second;
            curr+=x;
            pq.pop();
            if(curr>capacity) return 0;
        }
        return 1;
    }
};