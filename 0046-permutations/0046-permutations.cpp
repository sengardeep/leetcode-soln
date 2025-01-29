class Solution {
public: 
    void solve(vector<int>&arr,vector<vector<int>>&ans,int idx)
    {
        if(idx==arr.size())
        {
            ans.push_back(arr);
            return;
        }
        for(int i=idx;i<arr.size();i++)
        {
            swap(arr[i],arr[idx]);
            solve(arr,ans,idx+1);
            swap(arr[i],arr[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};