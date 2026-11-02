class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int num = nums[n/2];
        int ans = 0;
        for(auto x : nums) ans += abs(num-x);
        return ans;
    }
};