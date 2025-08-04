class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));

        return max(helper(nums, n - 1, n, 1, dp), helper(nums, n - 1, n, 0, dp));
    }

private:
    int helper(vector<int>& nums, int idx, int prevIdx, int flag, vector<vector<vector<int>>>& dp) {
        if (idx < 0) return 0;
        if (dp[idx][prevIdx][flag] != -1) return dp[idx][prevIdx][flag];

        int ans = helper(nums, idx - 1, prevIdx, flag, dp); // skip

        if (prevIdx == nums.size()) {
            ans = max(ans, 1 + helper(nums, idx - 1, idx, !flag, dp));
        } else {
            if (flag && nums[idx] > nums[prevIdx])
                ans = max(ans, 1 + helper(nums, idx - 1, idx, !flag, dp));
            else if (!flag && nums[idx] < nums[prevIdx])
                ans = max(ans, 1 + helper(nums, idx - 1, idx, !flag, dp));
        }

        return dp[idx][prevIdx][flag] = ans;
    }
};
