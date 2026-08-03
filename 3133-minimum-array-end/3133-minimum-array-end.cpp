class Solution {
public:
    long long minEnd(int n, int x) {
        int j=0;
        long long ans=0,num=x,y=n-1;
        for(int i=0;i<64;i++){
            if((num&(1LL<<i))){
                ans |= (1LL<<i);
                continue;
            }
            if((y&(1LL<<j))) ans|=(1LL<<i);
            j++;
        }
        return ans;
    }
};