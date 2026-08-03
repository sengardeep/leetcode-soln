class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i=0;
        while((1LL<<(i+1))<=left) i++;
        if((1LL<<(i+1))<right) return 0;
        int ans=left;
        for(long long k=left;k<=right;k++) ans=ans&k;
        return ans;
    }
};