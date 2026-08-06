class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                countStack.push(num);
                stringStack.push(curr);

                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int k = countStack.top();
                countStack.pop();

                string prev = stringStack.top();
                stringStack.pop();

                string temp = "";
                while (k--)
                    temp += curr;

                curr = prev + temp;
            }
            else {
                curr += c;
            }
        }

        return curr;
    }
};