class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] <= 0)
                nums[i] = n + 2;
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (idx < n)
                nums[idx] = (-1) * abs(nums[idx]);
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                ans++;
            else
                break;
        }
        return ans;
    }
};