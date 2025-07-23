class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;

        auto abOp = [](string &str) {
            int count = 0;
            stack<char> st;
            for (char ch : str) {
                if (ch == 'b') {
                    if (!st.empty() && st.top() == 'a') {
                        count++;
                        st.pop();
                    } else {
                        st.push(ch);
                    }
                } else {
                    st.push(ch);
                }
            }
            str.clear();
            while (!st.empty()) {
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());
            return count;
        };

        auto baOp = [](string &str) {
            int count = 0;
            stack<char> st;
            for (char ch : str) {
                if (ch == 'a') {
                    if (!st.empty() && st.top() == 'b') {
                        count++;
                        st.pop();
                    } else {
                        st.push(ch);
                    }
                } else {
                    st.push(ch);
                }
            }
            str.clear();
            while (!st.empty()) {
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());
            return count;
        };

        if (x > y) {
            ans += abOp(s) * x;
            ans += baOp(s) * y;
        } else {
            ans += baOp(s) * y;
            ans += abOp(s) * x;
        }

        return ans;
    }
};
