class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int p = 1 << n;
        vector<int> dp(p, -1);

        function<int(int)> f = [&](int mask) {
            int index = __builtin_popcount(mask);
            if (index == n)
                return 0;
            if (dp[mask] != -1)
                return dp[mask];

            int ans = INT_MAX;

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) {
                    ans = min(ans,
                              (nums1[index] ^ nums2[i]) + f((mask | (1 << i))));
                }
            }

            return dp[mask] = ans;
        };

        return f(0);
    }
};