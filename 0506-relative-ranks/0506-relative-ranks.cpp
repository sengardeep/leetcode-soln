class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> p;
        map<int, int> mp;
        int n = score.size();
        for (int i = 0; i < n; i++) {
            mp[score[i]] = i;
            p.push(score[i]);
        }
        vector<string> ans(n);
        int rank = 1;
        while (!p.empty()) {
            int top = p.top();
            p.pop();
            if (rank == 1)
                ans[mp[top]] = "Gold Medal";
            else if (rank == 2)
                ans[mp[top]] = "Silver Medal";
            else if (rank == 3)
                ans[mp[top]] = "Bronze Medal";
            else
                ans[mp[top]] = to_string(rank);
            rank++;
        }
        return ans;
    }
};