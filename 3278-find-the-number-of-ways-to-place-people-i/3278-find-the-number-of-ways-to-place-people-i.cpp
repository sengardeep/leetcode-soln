class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? (a[1] > b[1]) : a[0] < b[0];
        };
        sort(points.begin(), points.end(), cmp);
        int n = points.size(), ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int maxY = INT_MIN;
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                if(y2>y1) continue;
                if(y2>maxY) {
                    ans++;
                    maxY=max(maxY,y2);
                }
            }
        }

        return ans;
    }
};