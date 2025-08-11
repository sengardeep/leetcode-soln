class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int i = 0; i < 31; i++)
            if (n & (1 << i))
                powers.push_back(1 << i);

        vector<long long> prePro(powers.size(), 1LL);
        prePro[0] = powers[0];

        const int mod = 1e9 + 7;
        for (int i = 1; i < powers.size(); i++)
            prePro[i] = (prePro[i - 1] * 1LL * powers[i]) % mod;

        vector<int> ans;
        for (auto it : queries) {
            int l = it[0], r = it[1];
            int temp = prePro[r];
            if (l > 0)
                temp = (temp*1LL*binpow(prePro[l - 1],mod-2,mod))%mod;

            ans.push_back(temp);
        }

        return ans;
    }

private:
    long long binpow(long long a, long long b, long long m) {
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