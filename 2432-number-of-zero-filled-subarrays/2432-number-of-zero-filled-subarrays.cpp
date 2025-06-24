class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                count++;
            else {
                if (count == 0)
                    continue;
                else {
                    ans += sum(count);
                    count = 0;
                }
            }
        }
        if (count != 0)
            ans += sum(count);

        return ans;
    }

private:
    long long sum(int n) { return (n * 1LL * (n + 1)) / 2; }
};