class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return 0;
        int bits = __builtin_popcount(n - 1);
        // cout<<bits<<endl;
        return ((n & (n - 1)) == 0) && (bits % 2 == 0);
    }
};