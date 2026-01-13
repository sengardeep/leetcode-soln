class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double start = 0.0, end = 1e9;
        long double eps = 1e-5;
        
        auto check = [&](long double k) {
            long double a1 = 0.0, a2 = 0.0;
            for (auto &v : squares) {
                long double y = v[1], l = v[2];
                if (y >= k) {
                    a2 += l * l;
                } else if (y + l <= k) {
                    a1 += l * l;
                } else {
                    long double l1 = k - y;
                    long double l2 = y + l - k;
                    a1 += l * l1;
                    a2 += l * l2;
                }
            }
            return a1 - a2;
        };

        while (end - start > eps) {
            long double mid = (start + end) / 2;
            long double diff = check(mid);
            if (diff >= 0)
                end = mid;
            else
                start = mid;
        }
        return (double)start;
    }
};
