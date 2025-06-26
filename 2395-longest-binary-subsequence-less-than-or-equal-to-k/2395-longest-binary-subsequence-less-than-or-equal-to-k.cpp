class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0, n = s.size();
        long long x = 0;
        for (auto it : s)
            ans += it == '0';
        for (int i = 0; i < n; i++) {
            if (s[n - 1 - i] == '1') {
                if(i>64) break;
                x = x | (1ll << i);
                if (x <= k)
                    ans++;
                else
                    break;
            }
        }
        return ans;
    }
};