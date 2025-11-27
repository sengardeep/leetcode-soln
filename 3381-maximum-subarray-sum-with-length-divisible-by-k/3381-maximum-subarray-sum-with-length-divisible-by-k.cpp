class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        auto subSum = [&](vector<long long>& v) {
            long long ans = 0;
            long long res = 0;
            int flag = 0;
            for (int i = 0; i < v.size(); i++) {
                ans += v[i];
                if (ans < 0)
                    ans = 0;
                res=max(res,ans);
                flag = v[i] == 0;
            }
            if (!res && !flag)
                res = *max_element(begin(v), end(v));
            return res;
        };

        int n = nums.size();
        vector<long long> pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];
        auto rSum = [&](int l, int r) {
            long long ans = pre[r];
            if (l)
                ans -= pre[l - 1];
            return ans;
        };
        long long ans = -1e17;
        for (int i = 0; i <= k; i++) {
            vector<long long> temp;
            int idx = i;
            while (idx + k - 1 < n) {
                int nxt = idx + k - 1;
                temp.push_back(rSum(idx, nxt));
                idx = nxt + 1;
            }
            if(!temp.empty())
            ans = max(ans, subSum(temp));
        }
        return ans;
    }
};