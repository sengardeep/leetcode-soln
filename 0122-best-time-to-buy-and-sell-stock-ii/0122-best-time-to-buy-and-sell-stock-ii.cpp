class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                int idx = i;
                while (idx < prices.size() - 1 &&
                       prices[idx] < prices[idx + 1]) {
                    idx++;
                }
                ans += prices[idx] - prices[i];
                i = idx;
            }
        }

        return ans;
    }
};