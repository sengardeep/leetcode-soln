class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int op = 0;
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i])
                op++;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (auto it : s1)
            mp1[it]++;
        for (auto it : s2)
            mp2[it]++;
        for (auto it : s1) {
            if (mp1[it] != mp2[it])
                return 0;
        }
        return op <= 2;
    }
};