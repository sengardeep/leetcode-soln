class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i<nums.size()-1 && nums[i]==nums[i+1]) continue;
            if(nums[i]>0) ans+=nums[i];
        }
        if(ans==0) ans=*max_element(nums.begin(),nums.end());
        return ans;
    }
};