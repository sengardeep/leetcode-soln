class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;i++){
            int set = n & (1<<i);
            if(set) ans |= (1<<(31-i));
        }
        return ans;
    }
};