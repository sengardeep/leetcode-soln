class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        function<void(int)> f = [&](int index){
            if(index==nums.size()){
                ans.push_back(nums);
                return;
            }
            for(int i=index;i<nums.size();i++){
                swap(nums[i],nums[index]);
                f(index+1);
                swap(nums[i],nums[index]);
            }
        };
        f(0);
        return ans;
    }
};