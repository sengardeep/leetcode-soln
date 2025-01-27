class Solution {
public:
    const int MOD = 1e9 + 7;
    int calcPow(long long base, long long exp) {
        if (exp == 0)
            return 1;
        long long res = calcPow(base, exp / 2);
        if (exp & 1) {
            return (base * ((res * res * 1LL) % MOD)) % MOD;
        } else
            return (res * res * 1LL) % MOD;
    }
    int countGoodNumbers(long long n) {
        long long oddIdx = n / 2;
        long long evenIdx = n - oddIdx;
        return ((calcPow(5, evenIdx) % MOD) * 1LL *
                (calcPow(4, oddIdx) % MOD)) %
               MOD;
    }
};