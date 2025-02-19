class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Using Min-Heap
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            p;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            p.push(make_tuple(nums[i][0], i, 0));
            maxi = max(maxi, nums[i][0]);
        }
        int n = nums.size();

        vector<int> ans(2);
        int score = INT_MAX;
        while (!p.empty()) {
            int mini = get<0>(p.top());
            int row = get<1>(p.top());
            int col = get<2>(p.top());
            p.pop();
            if (maxi - mini < score) {
                ans = {mini, maxi};
                score = (maxi - mini);
            }
            if (col < nums[row].size() - 1) {
                maxi = max(maxi, nums[row][col + 1]);
                p.push(make_tuple(nums[row][col + 1], row, col + 1));
            } else
                break;
        }
        return ans;
    }
};