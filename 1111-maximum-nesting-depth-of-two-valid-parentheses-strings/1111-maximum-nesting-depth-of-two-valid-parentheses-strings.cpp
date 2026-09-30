class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int start = 1, end = n / 2;
        int ans = end;
        vector<int> res;
        auto check = [&](int k) {
            int count = 0;
            vector<int> vis(n, 0);
            for (int i = 0; i < n; i++) {
                if (seq[i] == '(') {
                    if (count == k)
                        continue;
                    vis[i] = 1;
                    count++;
                } else {
                    if (count >= 1) {
                        count--;
                        vis[i] = 1;
                    }
                }
            }
            count = 0;
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    if (seq[i] == '(')
                        count++;
                    else
                        count--;
                    if (count > k)
                        return 0;
                }
            }
            res = vis;
            return 1;
        };
        while (start <= end) {
            int mid = end + (start - end) / 2;
            if (check(mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }
};