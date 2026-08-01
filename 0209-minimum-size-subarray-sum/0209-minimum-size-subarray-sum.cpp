class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,sum=0,ans=n+1;
        while(j<n){
            sum+=nums[j];
            if(sum>=target) ans=min(ans,j-i+1);
            while(i<=j && sum>=target){
                ans=min(j-i+1,ans);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans==n+1?0:ans;
    }
};