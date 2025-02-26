class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        // Consider Positive only
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum < 0)
                sum = 0;
            ans = max(ans, sum);
        }
        // Consider Negative only
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum > 0)
                sum = 0;
            ans = max(ans, abs(sum));
        }
        return ans;
    }
};