class SparseTable {
    vector<vector<int>> table;
    vector<int> lg; // Precomputed logs for O(1) performance

public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        int max_log = log2(n) + 1;
        table.assign(n, vector<int>(max_log, 0));
        lg.assign(n + 1, 0);

        // Precompute log values for fast array-indexing lookups
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        // Base case: segments of length 1 (2^0)
        for (int i = 0; i < n; i++) {
            table[i][0] = arr[i];
        }

        // Compute table values for intervals with lengths as powers of 2
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                table[i][j] =
                    min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // O(1) Range Minimum Query
    int rangeMin(int l, int r) {
        int len = r - l + 1;
        int k = lg[len];
        return min(table[l][k], table[r - (1 << k) + 1][k]);
    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (!n)
            return 0;
        vector<int> pre(n, 0);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                pre[i] += 1;
            else
                pre[i] -= 1;
            if (i > 0)
                pre[i] += pre[i - 1];
            mp[pre[i]].push_back(i);
        }
        SparseTable st(pre);
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (pre[j] == 0 && st.rangeMin(0, j) >= 0) {
                ans = max(ans, j + 1);
            }

            if (mp.count(pre[j])) {
                auto &v = mp[pre[j]];
                int start = 0, end = v.size() - 1;
                int i = -1;
                while (start <= end) {
                    int mid = end + (start - end) / 2;
                    int idx = v[mid];
                    if (idx + 1 > j) {
                        end = mid - 1;
                        continue;
                    }
                    int mn = st.rangeMin(idx + 1, j);
                    if (mn >= pre[idx]) {
                        i = mid;
                        end = mid - 1;
                    } else
                        start = mid + 1;
                }
                if (i != -1)
                    ans = max(ans, j - v[i]);
            }
        }
        return ans;
    }
};