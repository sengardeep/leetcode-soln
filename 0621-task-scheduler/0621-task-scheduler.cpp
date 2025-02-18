class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto it : tasks) mp[it]++;
        priority_queue<int> p;
        for(auto it : mp) p.push(it.second);

        int ans=0;
        while(!p.empty())
        {
            vector<int> temp;
            for(int i=1;i<=n+1;i++)
            {
                if(!p.empty())
                {
                    int freq=p.top();
                    freq--;
                    temp.push_back(freq);
                    p.pop();
                }
            }
            for(auto it : temp) if(it>0) p.push(it); 
            if(p.empty()) ans+=temp.size(); //when no task left 
            else ans+=(n+1); //Otherwise n+1 will be added
        }
        return ans;
    }
};