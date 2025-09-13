class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> map(26,0);
        int v=0,c=0;
        for(int i=0;i<s.size();i++) {
            map[s[i]-'a']++;
            if(isVowel(s[i])) v=max(v,map[s[i]-'a']);
            else c=max(c,map[s[i]-'a']);
        }
        return c+v;
    }
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};