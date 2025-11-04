class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans;
        map<int,int> map;
        for(int i=0;i<k-1;i++) map[nums[i]]++;
        for(int i=k-1;i<n;i++){
            if(i>=k) map[nums[i-k]]--;
            map[nums[i]]++;
            priority_queue<pair<int,int>> pq;
            for(auto [num,f] : map) pq.push({f,num});
            int y=x,sum=0;
            while(!pq.empty()&&y--) {
                auto [f,num]=pq.top(); pq.pop();
                sum+=f*num;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};