class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int zero=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) continue;
            if(i<nums.size()-1&&nums[i]==nums[i+1]) 
            {
                nums[i]*=2;
                ans.push_back(nums[i]);
                nums[i+1]=0;
            }
            else ans.push_back(nums[i]);
        }
        for(int i=ans.size();i<nums.size();i++) ans.push_back(0);
        return ans;
    }
};