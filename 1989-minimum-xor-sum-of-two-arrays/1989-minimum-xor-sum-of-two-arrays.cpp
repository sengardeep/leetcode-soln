class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int p = 1 << n;
        vector<vector<int>> dp(n, vector<int>(p, -1));

        function<int(int, int)> f = [&](int index, int mask) {
            if (index == n)
                return 0;
            if (dp[index][mask] != -1)
                return dp[index][mask];

            int ans = INT_MAX;

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) {
                    ans = min(ans, (nums1[index] ^ nums2[i]) +
                                       f(index + 1, (mask | (1 << i))));
                }
            }

            return dp[index][mask] = ans;
        };

        return f(0, 0);
    }
};