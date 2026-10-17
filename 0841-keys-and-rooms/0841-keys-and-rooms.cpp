class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int> q;
        unordered_set<int> vis;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(vis.count(node)) continue;
            vis.insert(node);
            for(auto x : rooms[node]){
                if(!vis.count(x)) q.push(x);
            }
        }
        for(int i=1;i<n;i++) if(!vis.count(i)) return 0;
        return 1;
    }
};