class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<int,int> prev,curr;
        const int mod=1e9+7;
        for(auto it : nums) curr[it]++;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            curr[nums[i]]--;
            int p=prev[2*nums[i]],c=curr[2*nums[i]];
            ans=(ans+(p*1LL*c)%mod)%mod;
            prev[nums[i]]++;
        }
        return ans;
    }
};