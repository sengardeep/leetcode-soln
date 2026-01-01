class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> far(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            far[l] = max(far[l], r);
        }

        int taps = 0, currEnd = 0, maxReach = 0;

        for (int i = 0; i <= n; i++) {
            if (i > maxReach)
                return -1;

            if (i > currEnd) {
                taps++;
                currEnd = maxReach;
            }
            maxReach = max(maxReach, far[i]);
        }
        return taps;
    }
};