class Solution {
public:
    const int MOD = 1e9 + 7;
    const int N = 1e5 + 1;
    vector<int> fact, inv_fact;

    Solution() {
        fact.resize(N, 1);
        inv_fact.resize(N, 1);
        factorial();
        invFactorial();
    }

    int countAnagrams(string s) {
        int ans = 1;
        string temp = "";
        for (auto it : s) {
            if (it == ' ') {
                ans = (1LL * ans * ways(temp)) % MOD;
                temp = "";
            } else {
                temp += it;
            }
        }
        if (!temp.empty()) ans = (1LL * ans * ways(temp)) % MOD;
        return ans;
    }

private:
    int mod_exp(int base, int exp, int mod) {
        int result = 1;
        while (exp) {
            if (exp % 2 == 1)
                result = (1LL * result * base) % mod;
            base = (1LL * base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    void factorial() {
        for (int i = 2; i < N; i++) {
            fact[i] = (1LL * fact[i - 1] * i) % MOD;
        }
    }

    void invFactorial() {
        inv_fact[N - 1] = mod_exp(fact[N - 1], MOD - 2, MOD);
        for (int i = N - 2; i >= 0; i--) {
            inv_fact[i] = (1LL * inv_fact[i + 1] * (i + 1)) % MOD;
        }
    }

    int ways(const string &s) {
        int n = s.size();
        int total = fact[n];
        map<char, int> mp;
        for (auto it : s)
            mp[it]++;

        for (auto it : mp) {
            total = (1LL * total * inv_fact[it.second]) % MOD;
        }
        return total;
    }
};
