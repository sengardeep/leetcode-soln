class Solution {
public:
    void solve(string& s, vector<string>& ans, string& temp, int idx,
               unordered_map<char, string>& mp) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        string curr = mp[s[idx]];
        for (int i = 0; i < curr.size(); i++) {
            temp += curr[i];
            solve(s, ans, temp, idx + 1, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> keypad = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> ans;
        string temp;
        if (digits.empty())
            return ans;
        solve(digits, ans, temp, 0, keypad);
        return ans;
    }
};