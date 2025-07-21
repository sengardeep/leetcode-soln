class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int count = 1;
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 1 && s[i] == s[i + 1]) {
                count++;
            } else {
                if (count >= 2) {
                    ans += s[i];
                    ans += s[i];
                    count=1;
                }
                else ans+=s[i];
            }
        }
        return ans;
    }
};