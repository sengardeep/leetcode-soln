class Solution {
public:
    void generate(vector<int>& arr, int idx, vector<vector<int>>& ans, int k,
                  vector<int>& temp) {
        if (idx == arr.size()) {
            if (temp.size() == k) {
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(arr[idx]);
        generate(arr, idx + 1, ans, k, temp);
        temp.pop_back();

        generate(arr, idx + 1, ans, k, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        vector<int> temp;
        generate(nums, 0, ans, k, temp);
        return ans;
    }
};