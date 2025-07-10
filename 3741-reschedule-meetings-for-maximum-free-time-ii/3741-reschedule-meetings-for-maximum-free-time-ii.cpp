class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int ans = 0;
        vector<int> diff;
        startTime.push_back(eventTime);
        endTime.insert(endTime.begin(), 0);
        for (int i = 0; i < startTime.size(); i++) {
            diff.push_back(startTime[i] - endTime[i]);
        }
        startTime.pop_back();
        endTime.erase(endTime.begin());

        int n = diff.size();
        vector<int> suff(n, INT_MIN);
        suff[n - 1] = diff[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suff[i] = max(diff[i], suff[i + 1]);

        vector<int> pre(n, INT_MIN);
        pre[0] = diff[0];
        for (int i = 1; i < n; i++)
            pre[i] = max(diff[i], pre[i - 1]);

        for (int i = 0; i < n - 1; i++) {
            if (i < n - 2) {
                int curr = endTime[i] - startTime[i];
                if (suff[i + 2] >= curr)
                    ans = max(ans, diff[i] + diff[i + 1] + curr);
                else
                    ans = max(ans, diff[i] + diff[i + 1]);
            }
            if (i > 0) {
                int curr = endTime[i] - startTime[i];
                if (pre[i - 1] >= curr)
                    ans = max(ans, diff[i] + diff[i + 1] + curr);
                else
                    ans = max(ans, diff[i] + diff[i + 1]);
            }
        }

        return ans;
    }
};