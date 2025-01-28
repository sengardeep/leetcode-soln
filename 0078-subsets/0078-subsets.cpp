class Solution {
public: 
    void generate(vector<int> &arr,int idx,vector<vector<int>>&ans,vector<int> &temp)
    {
        if(idx==arr.size())
        {
            ans.push_back(temp);
            return;
        }
        //Selecting the element
        temp.push_back(arr[idx]);
        generate(arr,idx+1,ans,temp);
        temp.pop_back();
        //Ignoring the element
        generate(arr,idx+1,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        generate(nums,0,ans,temp);
        return ans;
    }
};