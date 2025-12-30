class Solution {
public:
    int largestPrime(int n) {
        vector<int> isPrime(n+1, 1);
        int ans=0,temp=0;
        isPrime[0] = isPrime[1] = 0;
        auto check=[&](int x){
            if(x<=1) return 0;
            for(int i=2;i<x;i++) if(x%i == 0) return 0;
            return 1;
        };
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                temp+=i;
                if(temp>n) break;
                if(check(temp)) ans=temp;
                for (long long j = i *1LL* i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        return ans;
    }
};