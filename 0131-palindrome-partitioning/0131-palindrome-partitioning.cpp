class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        // string res;
        solve(s, 0, temp, ans);
        return ans;
    }

private:
    // Function to check if a string is palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }

    // Backtracking function
    void solve(string& s, int idx, vector<string>& temp,
               vector<vector<string>>& ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, temp, ans);
                temp.pop_back();
            }
        }
    }
};