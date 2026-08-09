class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();

        function<void(int, int)> f = [&](int start, int remaining) {

            if (remaining == 0) {
                ans.push_back(temp);
                return;
            }

            for (int i = start; i < n; i++) {

                // Skip duplicate choices at the same level
                if (i > start && candidates[i] == candidates[i - 1])
                    continue;

                // Since sorted, everything after this is also too large
                if (candidates[i] > remaining)
                    break;

                // Take
                temp.push_back(candidates[i]);

                // i + 1 => this element cannot be reused
                f(i + 1, remaining - candidates[i]);

                // Backtrack
                temp.pop_back();
            }
        };

        f(0, target);

        return ans;
    }
};