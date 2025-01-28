class Solution {
public:
    void f(vector<int>& arr, int target, vector<vector<int>>& ans,
           vector<int>& temp, int sum, int idx) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            sum += arr[i];
            temp.push_back(arr[i]);
            f(arr, target, ans, temp, sum, i);
            temp.pop_back();
            sum -= arr[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        f(candidates, target, ans, temp, 0, 0);
        return ans;
    }
};