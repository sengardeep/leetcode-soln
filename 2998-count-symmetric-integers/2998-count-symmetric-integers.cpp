class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++)
            ans += check(i);
        return ans;
    }

private:
    bool check(int n) {
        int digi = 0;
        vector<int> v;
        while (n) {
            digi++;
            v.push_back(n % 10);
            n /= 10;
        }
        if (digi & 1)
            return 0;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < digi; i++) {
            if (i < digi / 2)
                sum1 += v[i];
            else
                sum2 += v[i];
        }
        return (sum1 == sum2);
    }
};