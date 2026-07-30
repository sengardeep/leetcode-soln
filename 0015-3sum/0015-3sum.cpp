class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        for (int i = 0; i < n - 2; i++) {
            int target = -nums[i];
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    if (st.count(temp)) {
                        k--;
                        j++;
                        continue;
                    }
                    ans.push_back(temp);
                    st.insert(temp);
                    k--;
                    j++;
                } else if (sum < target)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};