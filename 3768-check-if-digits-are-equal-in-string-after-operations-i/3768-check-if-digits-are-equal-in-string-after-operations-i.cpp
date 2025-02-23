class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string temp = "";
            for (int i = 0; i < s.size() - 1; i++) {
                int first = s[i];
                int second = s[i+1];
                int res = (first + second) % 10;
                temp += to_string(res);
            }
            s = temp;
            // cout<<s<<" ";
        }
        // cout<<s[0]<<" "<<s[1]<<endl;
        return s[0] == s[1];
    }
};