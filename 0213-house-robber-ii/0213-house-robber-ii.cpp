class Solution {
   public:
    int rob(vector<int>& money) {
        int n = money.size();
        if(n==1) return money[0];
        vector<int> dp1(n, -1);
        int first=helper(money, n - 1, dp1, 1);
        vector<int> dp2(n,-1);
        int second=helper(money, n - 2, dp2, 0);
        return max(first,second);
    }

   private:
    int helper(vector<int>& nums, int idx, vector<int>& dp, int start) {
        if (idx < start) return 0;
        if (dp[idx] != -1) return dp[idx];

        // Take current index and move to idx - 2
        int take = nums[idx] + helper(nums, idx - 2, dp, start);

        // Or skip current index and move to idx - 1
        int skip = helper(nums, idx - 1, dp, start);

        return dp[idx] = max(take, skip);
    }
};