class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int sum = 0, n = candidates.size();
        set<vector<int>> res;
        function<void(int)> f = [&](int i) -> void {
            if (sum > target)
                return;
            if (i == n) {
                if (sum == target)
                    res.insert(temp);
                return;
            }
            temp.push_back(candidates[i]);
            sum += candidates[i];
            f(i);
            f(i + 1);
            temp.pop_back();
            sum -= candidates[i];
            f(i + 1);
        };
        f(0);
        vector<vector<int>> ans(begin(res), end(res));
        return ans;
    }
};