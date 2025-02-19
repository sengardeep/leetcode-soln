class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it : nums) mp[it]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(auto it : mp)
        {
            if(p.size() < k)
            p.push(make_pair(it.second,it.first));
            else
            {
                if(it.second > p.top().first)
                {
                    p.pop();
                    p.push(make_pair(it.second,it.first));
                }
            }
        }
        vector<int> ans;
        while(!p.empty())
        {
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};