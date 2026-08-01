class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int i = 0, j = 0, ans = 0;
        int mx = 0, rem = 0;
        while (j < s.size()) {
            freq[s[j] - 'A']++;
            mx = max(mx, freq[s[j] - 'A']);
            rem = (j - i + 1) - mx;
            if (i <= j && rem > k) {
                freq[s[i] - 'A']--;
                mx = *max_element(begin(freq), end(freq));
                rem = (j - i + 1) - mx;
                i++;
            }
            if (rem <= k)
                ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};