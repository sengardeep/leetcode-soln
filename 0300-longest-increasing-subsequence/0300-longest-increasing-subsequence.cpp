class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (ans.empty() || ans.back() < nums[i])
                ans.push_back(nums[i]);
            else {
                int lb =
                    lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[lb] = nums[i];
            }
        }

        return ans.size();
    }
};