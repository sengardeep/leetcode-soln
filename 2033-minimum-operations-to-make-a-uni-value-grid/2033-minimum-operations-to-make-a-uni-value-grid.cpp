class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (auto it : grid)
            for (auto i : it)
                v.push_back(i);
        sort(begin(v), end(v));
        int n = v.size();
        auto helper = [&](int mid) {
            int ans = 0;
            for (auto i : v)
                ans += (abs(mid - i) / x);
            return ans;
        };
        int mid = v[n / 2];
        int ans = 0;
        if (((mid - v[0]) % x) != 0) {
            mid -= ((mid - v[0]) % x);
            for (auto i : v)
                if ((abs(mid - i)) % x)
                    return -1;

            ans = min(helper(mid), helper(mid + x));
        } else {
            for (auto i : v)
                if ((abs(mid - i)) % x)
                    return -1;

            ans = helper(mid);
        }
        return ans;
    }
};