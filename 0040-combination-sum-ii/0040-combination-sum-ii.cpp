class Solution {
public:
    void generate(vector<int>& arr, int idx, int target,
                  vector<vector<int>>& ans, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            if (i > idx && arr[i] == arr[i - 1])
                continue; // Skip duplicates
            if (arr[i] > target)
                break; // Stop early as the array is sorted
            temp.push_back(arr[i]);
            generate(arr, i + 1, target - arr[i], ans,
                     temp); // Move to the next index
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        generate(candidates, 0, target, ans, temp);
        return ans;
    }
};
