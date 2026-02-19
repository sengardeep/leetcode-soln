class Solution {
public:
    int countBinarySubstrings(string s) {
        int zero=0,one=0,ans=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                while(i<n && s[i]=='0') 
                {
                    zero++;
                    i++;
                }
                i--;
            ans+=min(zero,one);
            one=0;
            }else{
                while(i<n && s[i]=='1') 
                {
                    one++;
                    i++;
                }
                i--;
            ans+=min(zero,one);
            zero=0;
            }
        }
        return ans;
    }
};