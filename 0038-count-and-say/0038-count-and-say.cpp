class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        while (n-- > 1) {
            string temp = "";
            for (int i = 0; i < curr.size(); i++) {
                int idx = i;
                while (curr[idx] == curr[i] && idx < curr.size())
                    idx++;
                int length = idx - i;
                string c = to_string(length);
                temp += c;
                temp += curr[i];
                i = idx - 1;
            }
            curr = temp;
        }
        return curr;
    }
};