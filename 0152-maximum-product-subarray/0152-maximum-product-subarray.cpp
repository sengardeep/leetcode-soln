class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0],mn = nums[0],ans = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];

            int p = mx * x;
            int q = mn * x;

            mx = max({x, p, q});
            mn = min({x, p, q});

            ans = max(ans, mx);
        }
        return ans;
    }
};