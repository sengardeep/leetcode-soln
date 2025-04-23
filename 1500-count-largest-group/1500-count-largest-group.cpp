class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> freq(37, 0);
        for (int i = 1; i <= n; i++)
            freq[sum(i)]++;
        int maxi = *max_element(freq.begin(), freq.end());
        int ans = 0;
        for (auto it : freq)
            ans += (it == maxi);
        return ans;
    }

private:
    int sum(int n) {
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
};