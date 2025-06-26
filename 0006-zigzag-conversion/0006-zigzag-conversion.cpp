class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int down = 2 * numRows - 2, n = s.size(), up = 0;
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            int j = i;
            bool flag = true;
            while (j < n) {
                ans += s[j];
                if (up == 0)
                    flag = true;
                if (down == 0)
                    flag = false;
                if (flag) {
                    j += down;
                    flag = false;
                } else {
                    j += up;
                    flag = true;
                }
            }
            up += 2;
            down -= 2;
        }

        return ans;
    }
};