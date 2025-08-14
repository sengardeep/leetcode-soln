class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();
        for (int i = 0; i < n - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                if (ans.empty() || ans[0] < num[i]) {
                    if (ans.empty()) {
                        ans += num[i];
                        ans += num[i];
                        ans += num[i];
                    } else {
                        ans[0] = num[i];
                        ans[1] = num[i];
                        ans[2] = num[i];
                    }
                }
            }
        }
        return ans;
    }
};