class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        for(int i=0;i+1<nums.size();i++){
            if(nums[i]==nums[i+1]) {
                continue;
            }
            if(nums[i]>nums[i+1]){
                int j=i+1;
                while(j+1<nums.size() && nums[j]>nums[j+1]) j++;
                ans=max(ans,j-i+1);
                i=j-1;
            }else{
                int j=i+1;
                while(j+1<nums.size() && nums[j]<nums[j+1]) j++;
                ans=max(ans,j-i+1);
                i=j-1;
            }
        }
        return ans;
    }
};