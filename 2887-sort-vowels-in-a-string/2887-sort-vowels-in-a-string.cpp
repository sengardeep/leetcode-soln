class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        int n=s.size();
        for(int i=0;i<n;i++) if(isVowel(s[i])) v.push_back(s[i]);
        sort(begin(v),end(v));
        int j=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                s[i]=v[j];
                j++;
            }
        }
        return s;
    }

private:
    bool isVowel(char c) {
        c = std::tolower(static_cast<unsigned char>(c));
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};