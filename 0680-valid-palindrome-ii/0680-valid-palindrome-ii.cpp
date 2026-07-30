class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1,flag=1;
        auto check=[&](int x,int y){
            while(x<y){
                if(s[x]==s[y]) {
                    x++;
                    y--;
                }else return 0;
            }
            return 1;
        };
        while(i<j){
            if(s[i]==s[j]) {
                i++;
                j--;
            }else{
                if(check(i+1,j)) i++;
                else if(check(i,j-1)) j--;
                else return 0;
            }
        }
        return 1;
    }
};