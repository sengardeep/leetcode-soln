struct SparseTable {
    int n, LOG;
    vector<vector<int>> stMin, stMax;
    vector<int> log2;

    SparseTable(const vector<int>& nums) {
        n = nums.size();
        LOG = 32 - __builtin_clz(n);

        stMin.assign(n, vector<int>(LOG));
        stMax.assign(n, vector<int>(LOG));
        log2.assign(n + 1, 0);

        for (int i = 2; i <= n; i++)
            log2[i] = log2[i / 2] + 1;

        for (int i = 0; i < n; i++) {
            stMin[i][0] = nums[i];
            stMax[i][0] = nums[i];
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                stMin[i][k] =
                    min(stMin[i][k - 1], stMin[i + (1 << (k - 1))][k - 1]);
                stMax[i][k] =
                    max(stMax[i][k - 1], stMax[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    int rangeMin(int L, int R) {
        int k = log2[R - L + 1];
        return min(stMin[L][k], stMin[R - (1 << k) + 1][k]);
    }

    int rangeMax(int L, int R) {
        int k = log2[R - L + 1];
        return max(stMax[L][k], stMax[R - (1 << k) + 1][k]);
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        SparseTable st(nums);

        long long ans = 0;

        for (int L = 0; L < n; L++) {

            int low = L, high = n - 1;
            int bestR = L - 1;

            while (low <= high) {
                int mid = (low + high) / 2;

                int mn = st.rangeMin(L, mid);
                int mx = st.rangeMax(L, mid);
                long long score = (mx - mn) *1LL* (mid-L+1);
                if (score <= k) {
                    bestR = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans += (bestR - L + 1);
        }
        return ans;
    }
};
