class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<s.size() && !isalnum(s[i])) i++;
            while(j>=0 && !isalnum(s[j])) j--;
            if(i>=j) break;
            if(s[i]>=65 && s[i]<=90) s[i]=tolower(s[i]);
            if(s[j]>=65 && s[j]<=90) s[j]=tolower(s[j]);
            if(s[i]==s[j]) {
                i++;
                j--;
            }else return 0;
        }
        return 1;
    }
};