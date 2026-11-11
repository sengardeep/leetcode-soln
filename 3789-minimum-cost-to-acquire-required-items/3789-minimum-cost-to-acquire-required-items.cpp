class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long ans = 0;
        int mn = min(need1, need2);
        ans = min(mn * 1LL * costBoth, mn * 1LL * (cost1 + cost2));
        need1 -= mn;
        need2 -= mn;
        ans += min(need1 * 1LL * costBoth, need1 * 1LL * cost1);
        ans += min(need2 * 1LL * costBoth, need2 * 1LL * cost2);
        return ans;
    }
};