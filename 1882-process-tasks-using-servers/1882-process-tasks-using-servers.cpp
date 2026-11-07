class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> available; //weight,index
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> busy; //time,index
        for(int i=0;i<servers.size();i++) available.push({servers[i],i});
        long long time=0,j=0;
        while(j<tasks.size()){
            if(available.empty()){
                time=max(time,(long long)busy.top().first);
            }
            time=max(time,j);
            while(!busy.empty() && busy.top().first <= time) {
                auto [t,i] = busy.top();
                busy.pop();
                available.push({servers[i],i});
            }
            auto [server,index] = available.top();
            available.pop();
            busy.push({time+tasks[j],index});
            tasks[j]=index;
            j++;
        }
        return tasks;
    }
};