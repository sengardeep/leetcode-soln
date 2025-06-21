class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        vector<int> map(26, 0);
        for (auto it : word)
            map[it - 'a']++;
        int ans = n - 1;
        for (int i = 0; i <= n; i++) {
            int lo = i, hi = i + k;
            int count = 0;
            for (int j = 0; j < 26; j++) {
                if (map[j] < lo)
                    count += map[j];
                if (map[j] > hi)
                    count += (map[j] - hi);
            }
            ans = min(ans, count);
        }

        return ans;
    }
};