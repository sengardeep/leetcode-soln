class Solution {
public: 
    void generate(vector<int>&arr,vector<vector<int>>&ans,vector<int>&temp,int idx)
    {
        ans.push_back(temp);
        for(int i=idx;i<arr.size();i++)
        {
            if(i>idx && arr[i]==arr[i-1]) continue;
            temp.push_back(arr[i]);
            generate(arr,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        generate(nums,ans,temp,0);
        return ans;
    }
};