class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 0, count = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == word[i + 1])
                count++;
            else {
                ans += count;
                count = 0;
            }
        }
        ans += count;
        return ans+1;
    }
};