class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        int total = 1<<n;
        set<vector<int>> res;
        for(int k=0;k<total;k++){
            vector<int> temp;
            for(int i=0;i<n;i++){
                if(k&(1<<i)) temp.push_back(nums[i]);
            }
            sort(begin(temp),end(temp));
            res.insert(temp);
        }
        vector<vector<int>> ans(begin(res),end(res));
        return ans;
    }
};