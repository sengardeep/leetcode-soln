class Solution {
    long long MOD = 1e9 + 7;

public:
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2, odd = n / 2;
        int ans =
            ((power(5, even, MOD) % MOD) * (power(4, odd, MOD) % MOD)) % MOD;
        return ans;
    }

private:
    long long power(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
};