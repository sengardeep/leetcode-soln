class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zero = count(begin(s),end(s),'0');
        int one = 0;
        int ans=one+zero;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') zero--;
            else one++;
            ans = min(ans,one+zero);
        }
        return ans;
    }
};