class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;
        for(auto it : nums) mp[it]++;
        int prev=1e9+2,curr=-1;
        int prevCount=0,currCount=0;
        int ans=0;
        for(auto it : mp)
        {
            curr=it.first;
            currCount=it.second;
            if(curr-prev == 1)
            {
                ans=max(ans,prevCount+currCount);
            }

            prev=curr;
            prevCount=currCount;
        }

        return ans;
        
    }
};