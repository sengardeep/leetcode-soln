class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<long long> suf(nums.size(),0);
        suf[nums.size()-1]=nums.back();
        long long ans=-1e18,sum=0;
        for(int i=nums.size()-2;i>=0;i--) suf[i]=min(suf[i+1],(long long)nums[i]);
        for(int i=0;i<nums.size()-1;i++) {
            sum+=nums[i];
            ans=max(ans,sum-suf[i+1]);
        }
        return ans;
    }
};