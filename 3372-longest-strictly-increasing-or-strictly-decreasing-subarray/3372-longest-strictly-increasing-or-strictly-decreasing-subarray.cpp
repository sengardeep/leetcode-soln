class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if( nums[i]<nums[i+1]) //Increasing
            {
                int idx=i;
                while(i<nums.size()-1 &&nums[i]<nums[i+1]) i++;
                ans=max(ans,i-idx+1);
                i-=1;
            }
            else if(nums[i]>nums[i+1]) //Decreasing
            {
                int idx=i;
                while(i<nums.size()-1 && nums[i]>nums[i+1]) i++;
                ans=max(ans,i-idx+1);
                i-=1;
            }
        }
        return ans;
    }
};