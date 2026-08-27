class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        function<void(int)> f = [&](int index){
            if(index==nums.size()){
                res.insert(nums);
                return;
            }
            for(int i=index;i<nums.size();i++){
                swap(nums[i],nums[index]);
                f(index+1);
                swap(nums[i],nums[index]);
            }
        };
        f(0);
        vector<vector<int>> ans(begin(res),end(res));
        return ans;
    }
};