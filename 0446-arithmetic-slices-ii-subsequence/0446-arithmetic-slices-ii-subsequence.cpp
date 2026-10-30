class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        map<pair<int, long long>, int> dp;
        int count=0; 
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                dp[{j, (long long)nums[j] - nums[i]}] += 1;
                count++;
            }
        }
        for (int i = 2; i < n; i++) {
            for (int j = 1; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];
                if (dp.count({j, diff})) {
                    int val = dp[{j, diff}];
                    // cout<<i<<" "<<j<<" "<<val<<endl;
                    dp[{i, diff}] += val;
                }
            }
        }
        int ans = 0;
        for (auto [p, x] : dp)
            ans = ans + x;
        return ans-count;
    }
};