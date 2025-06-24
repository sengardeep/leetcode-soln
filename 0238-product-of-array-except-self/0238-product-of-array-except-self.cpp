class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int n = nums.size();
        ans[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            ans[i] = ans[i + 1] * nums[i];

        int pro = 1;
        for (int i = 0; i < n; i++) {
            if (i < n - 1)
                ans[i] = ans[i + 1] * pro;
            else
                ans[i] = pro;
            pro *= nums[i];
        }
        return ans;
    }
};