class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int count=0,ans=1;
        for(auto it : nums){
            if(it==maxi){
                count++;
            }
            else
            {
                ans=max(ans,count);
                count=0;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};