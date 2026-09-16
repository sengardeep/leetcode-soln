class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int> vis(n, 1);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[j]) {
                    if (triplets[j][i] > target[i])
                        vis[j] = 0;
                }
            }
        }
        vector<int> flag(3,0);
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < n; i++) {
                if (vis[i] && triplets[i][j] == target[j])
                    flag[j] = 1;
            }
        }
        for (auto x : flag)
            if (!x)
                return x;
        return 1;
    }
};