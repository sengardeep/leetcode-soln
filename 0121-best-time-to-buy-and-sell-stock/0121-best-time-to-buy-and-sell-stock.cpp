class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, maxi = INT_MIN;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (mini > prices[i]) {
                mini = min(mini, prices[i]);
                maxi = INT_MIN;
                continue;
            }

            maxi = max(maxi, prices[i]);

            ans = max(maxi - mini, ans);
        }
        return ans;
    }
};