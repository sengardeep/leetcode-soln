class Solution {
public:
    int superPow(int a, vector<int>& b) {
        // We'll use large exponentiation
        // since phi(m)=1140

        int new_b = 0;
        for (auto it : b) {
            if(new_b*10 + it > 1140) 
            new_b = (new_b*10 + it) % 1140;
            else
            new_b = (new_b*10 + it);
        }
        return f1(a, new_b, 1337);
    }

private:
    int f1(int a, int b, int m) {
        a %= m;
        int ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return ans;
    }
};