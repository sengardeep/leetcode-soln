class Solution {
public:
    string smallestNumber(string pattern) {
        string num = "";
        for (int i = 0; i <= pattern.size(); i++) {
            num += to_string(i + 1);
        }
        while (!check(num, pattern)) {
            next_permutation(num.begin(),num.end());
        }
        return num;
    }

private:
    bool check(string& num, string& pattern) {
        for (int i = 0; i < pattern.size(); i++) {
            if ((pattern[i] == 'I' && num[i] > num[i + 1]) ||
                (pattern[i] == 'D' && num[i] < num[i + 1]))
                return false;
        }
        return true;
    }
};