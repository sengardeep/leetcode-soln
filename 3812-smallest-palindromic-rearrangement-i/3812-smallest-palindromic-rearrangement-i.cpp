class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1) return s;
        map<char, int> mp;
        for (auto it : s)
            mp[it]++;
        string odd = "";
        string ans = "";
        for (auto it : mp) {
            if (it.second & 1) {
                odd += it.first;
                mp[it.first] -= 1;
            }
            int freq = (it.second) / 2;
            while(freq--) ans += (it.first);
        }
        string copy = ans;
        reverse(copy.begin(), copy.end());
        if (odd != "")
            ans += odd;
        ans += copy;

        return ans;
    }
};