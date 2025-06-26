class Solution {
public:
    string reverseWords(string s) {
        string ans = "", temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (temp.size() > 0) {
                    reverse(temp.begin(), temp.end());
                    ans += temp;
                    ans += " ";
                    temp = "";
                }
            } else
                temp += s[i];
        }
        if (temp.size() > 0) {
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += " ";
            temp = "";
        }
        reverse(ans.begin(), ans.end());
        ans.erase(0, 1);
        return ans;
    }
};