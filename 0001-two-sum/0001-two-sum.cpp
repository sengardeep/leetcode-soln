class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=nums[i];
        }
        sort(ans.begin(),ans.end());
        int start=0,end=ans.size()-1;
        int ans1=0,ans2=0;
        while(start<end)
        {
            if(ans[start]+ans[end]==target) 
            {
                ans1=ans[start];
                ans2=ans[end];
                break;
            } 
            else if((ans[start]+ans[end])>target) end--;
            else start++;
        }
        vector<int> sol;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ans1||nums[i]==ans2) sol.push_back(i);
            else continue; 
        }
        return sol;
    }
};