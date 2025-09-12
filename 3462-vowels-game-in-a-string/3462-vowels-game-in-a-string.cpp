class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels=0;
        for(auto c : s) vowels += (isVowel(c));
        return (vowels!=0);
    }
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};