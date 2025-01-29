class Solution {
public:
    void solve(vector<int>& arr, vector<vector<int>>& ans, int idx,
               vector<int>& temp, int target, int size) {
        if (temp.size() == size || idx == arr.size() || target < 0) {
            if (target == 0 && temp.size() == size) {
                ans.push_back(temp);
            }
            return;
        }
        // select
        temp.push_back(arr[idx]);
        solve(arr, ans, idx + 1, temp, target - arr[idx], size);
        temp.pop_back();

        // Not select
        solve(arr, ans, idx + 1, temp, target, size);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for (int i = 1; i <= 9; i++)
            nums.push_back(i);
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums, ans, 0, temp, n, k);
        return ans;
    }
};