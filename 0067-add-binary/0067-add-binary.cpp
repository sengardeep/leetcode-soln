class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(),m=b.size();
        string ans="";
        int i=n-1,j=m-1,carry=0;
        while(i>=0 && j>=0){
            int x=a[i]-'0',y=b[j]-'0';
            if(x==y && x==0){
                if(carry) {
                    carry=0;
                    ans+='1';
                }else ans+='0';
            }else if(x==y && x==1){
                if(carry) ans+='1';
                else {
                    ans+='0';
                    carry=1;
                }
            }else{
                if(carry){
                    ans+='0';
                    carry=1;
                }else{
                    ans+='1';
                }
            }
            i--;
            j--;
        }
        while(i>=0){
            int x=a[i]-'0';
            if(x && carry) ans+='0';
            else if((!x && carry) || (x && !carry)){
                carry=0;
                ans+='1';
            }
            else ans+='0';
            i--;
        }
        while(j>=0){
            int x=b[j]-'0';
            if(x && carry) ans+='0';
            else if((!x && carry) || (x && !carry)){
                carry=0;
                ans+='1';
            }
            else ans+='0';
            j--;
        }
        if(carry) ans+='1';
        reverse(begin(ans),end(ans));
        return ans;
    }
};