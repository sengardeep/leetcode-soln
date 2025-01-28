class Solution {
public:
    void f(vector<int>& arr, int index, vector<vector<int>>& ans,
           vector<int>& temp, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
            return;
        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1])
                continue;
            temp.push_back(arr[i]);
            f(arr, i + 1, ans, temp, target - arr[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        f(candidates, 0, ans, temp, target);

        return ans;
    }
};