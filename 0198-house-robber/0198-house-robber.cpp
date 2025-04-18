class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, n - 1, dp);
    }

private:
    int helper(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];

        // Take current index and move to idx - 2
        int take = nums[idx] + helper(nums, idx - 2, dp);

        // Or skip current index and move to idx - 1
        int skip = helper(nums, idx - 1, dp);

        return dp[idx] = max(take, skip);
    }
};
