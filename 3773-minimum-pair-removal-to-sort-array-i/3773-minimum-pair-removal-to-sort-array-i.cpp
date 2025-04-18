class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;

        while (true) {
            bool flag = true;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                break;
            int minIdx = -1, minVal = INT_MAX;
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minVal) {
                    minIdx = i;
                    minVal = sum;
                }
            }
            ans++;
            nums.erase(nums.begin() + minIdx);
            nums.erase(nums.begin() + minIdx);
            nums.insert(nums.begin() + minIdx, minVal);
        }
        return ans;
    }
};