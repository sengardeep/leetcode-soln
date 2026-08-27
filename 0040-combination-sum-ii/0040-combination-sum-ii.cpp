class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        function<void(int,int)> f=[&](int index,int rem){
            if(rem==0) ans.push_back(temp);
            for(int i=index;i<n;i++){
                if(i>index && nums[i]==nums[i-1]) continue;
                if(nums[i]>rem) break;
                temp.push_back(nums[i]);
                f(i+1,rem-nums[i]);
                temp.pop_back();
            }
        };
        f(0,target);
        return ans;
    }
};