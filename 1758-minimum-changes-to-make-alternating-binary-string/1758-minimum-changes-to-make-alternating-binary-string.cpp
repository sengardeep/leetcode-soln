class Solution {
public:
    int minOperations(string s) {
        int flag=0,ans1=0,ans2=0;
        for(auto c : s){
            if(!flag && c=='1') ans1++;
            if(flag && c=='0') ans1++;
            flag^=1;
        }
        flag=1;
        for(auto c : s){
            if(!flag && c=='1') ans2++;
            if(flag && c=='0') ans2++;
            flag^=1;
        }
        return min(ans1,ans2);
    }
};