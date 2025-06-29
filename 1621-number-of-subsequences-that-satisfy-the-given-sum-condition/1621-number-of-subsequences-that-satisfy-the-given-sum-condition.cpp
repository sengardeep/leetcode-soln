class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] * 2 > target)
                break;
            int x = target - nums[i];
            auto it = upper_bound(nums.begin(), nums.end(), x);
            int idx = -1;
            if (it == nums.end())
                idx = n - 1;
            else
                idx = it - nums.begin() - 1;
            int count = idx - i;

            ans = (ans + binExpo(2, count, MOD)) % MOD;
        }
        return ans;
    }

private:
    int binExpo(int base, int p, int MOD) {
        if (p == 0)
            return 1;

        int ans = binExpo(base, p / 2, MOD);

        if (p & 1)
            return (base * 1LL * (ans * 1LL * ans) % MOD) % MOD;
        else
            return (ans * 1LL * ans) % MOD;
    }
};