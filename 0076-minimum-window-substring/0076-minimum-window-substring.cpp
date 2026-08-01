class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int length = 1e5,index=-1;
        vector<int> freq(60, 0);
        for (auto c : t)
            freq[c - 'A']++;
        vector<int> occ(60, 0);
        int i = 0, j = 0;
        int flag = 0;
        while (j < s.size()) {
            occ[s[j] - 'A']++;
            flag = 1;
            for (int k = 0; k < 60; k++) {
                if (occ[k] < freq[k]) {
                    flag = 0;
                    break;
                }
            }
            while (i<=j && flag) {
                int curr = j - i + 1;
                if (curr < length) {
                    length = curr;
                    index=i;
                }
                occ[s[i] - 'A']--;
                if (freq[s[i] - 'A'] > 0 &&
                    occ[s[i] - 'A'] < freq[s[i] - 'A']) {
                    flag = 0;
                }
                i++;
            }
            j++;
        }
        if(length>=1e5) return "";
        ans=s.substr(index,length);
        return ans;
    }
};