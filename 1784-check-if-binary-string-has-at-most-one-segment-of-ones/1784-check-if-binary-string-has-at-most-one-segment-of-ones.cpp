class Solution {
public:
    bool checkOnesSegment(string s) {
        int one=0,count=0;
        for(char c : s){
            if(c=='1') one++;
            else {
                if(one) count++;
                one=0;
            }
        }
        if(one) count++;
        return count<=1;
    }
};