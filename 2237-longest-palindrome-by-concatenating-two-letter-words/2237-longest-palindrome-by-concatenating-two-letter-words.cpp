class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (auto it : words)
            mp[it]++;

        int ans = 0;
        bool flag = true;
        for (auto it : words) {
            string s = it;
            reverse(s.begin(), s.end());
            if (s == it) {
                if (mp[s] >= 2) {
                    ans += 4;
                    mp[s] -= 2;
                } else if (mp[s] == 1 && flag) {
                    ans += 2;
                    mp[s] = 0;
                    flag = false;
                }
            }
            else
            {
                if(mp[s] > 0 && mp[it] > 0) 
                {
                    ans += 4;
                    mp[it]--;
                    mp[s]--;
                }
            }
        }
        return ans;
    }
};