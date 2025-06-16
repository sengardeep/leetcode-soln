class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int maxi = INT_MIN, mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (mini >= nums[i])
                mini = nums[i];
            else {
                maxi = nums[i];
                ans = max(ans, maxi - mini);
            }
        }

        return ans;
    }
};