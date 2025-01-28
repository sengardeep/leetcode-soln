class Solution {
public:
    void f(vector<int>& arr, vector<vector<int>>& ans, vector<int>& temp,
           int index, int target, int k) {
        if (temp.size() == k) {
            if (target == 0)
                ans.push_back(temp);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            temp.push_back(arr[i]);
            f(arr, ans, temp, i + 1, target - arr[i], k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> temp;

        f(arr, ans, temp, 0, n, k);

        return ans;
    }
};