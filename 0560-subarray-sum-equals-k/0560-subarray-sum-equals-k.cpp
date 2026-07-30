class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=1;
        int ans=0,sum=0;
        for(int x : nums)
        {
            sum+=x;
            int target=sum-k;
            if(mp.count(target)) ans+=mp[target];
            mp[sum]++;
        }
        return ans;
    }
};