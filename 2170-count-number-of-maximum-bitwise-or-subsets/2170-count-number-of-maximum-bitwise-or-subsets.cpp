class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int orVal=0;
        for(auto it : nums) orVal|=it;
        int n=nums.size(),ans=0;
        for(int mask = 1; mask < (1<<n); mask++){
            int temp=0;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)) {
                    temp |= nums[i];
                }
            }
            ans+=(temp==orVal);
        }
        return ans;
    }
};