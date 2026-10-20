class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> divisors;
        for (int i = 1; i <= n; i++)
            if (n % i == 0)
                divisors.push_back(i);
        vector<int> target_indices(n);
        iota(target_indices.begin(), target_indices.end(), 0);

        stable_sort(target_indices.begin(), target_indices.end(),
                    [&](int i, int j) { return nums[i] < nums[j]; });

        vector<int> final_positions(n);
        for (int sorted_pos = 0; sorted_pos < n; ++sorted_pos) {
            final_positions[target_indices[sorted_pos]] = sorted_pos;
        }
        int ans = 0;
        for (int k : divisors) {
            int flag = 1;
            int drops = 0;
            for (int i = 0; i < n; i++) {
                int final_position = final_positions[i];
                if (k == 1 && final_position != i) {
                    flag = 0;
                    break;
                }
                int d = i / k;
                int left = d * k, right = (d + 1) * k;
                if (final_position < left || final_position >= right) {
                    flag = 0;
                    break;
                }
                if (i == left)
                    drops = 0;
                int next_i = (i + 1 < right) ? (i + 1) : left;
                if (nums[i] > nums[next_i]) {
                    drops++;
                }
                if (drops > 1) {
                    flag = 0;
                    break;
                }
            }
            ans += (flag ? k : 0);
        }
        return ans;
    }
};