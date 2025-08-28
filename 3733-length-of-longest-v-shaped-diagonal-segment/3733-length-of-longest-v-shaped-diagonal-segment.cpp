class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        pair<int, int> dir[4] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
        int cw[4] = {3, 0, 1, 2}; // clockwise diagonal mapping

        // use vector instead of VLA
        vector<vector<vector<vector<int>>>> dp(
            m, vector<vector<vector<int>>>(
                   n, vector<vector<int>>(
                          4, vector<int>(2, -1))));

        function<int(int, int, int, int)> f = [&](int r, int c, int d, int flag) -> int {
            if (r < 0 || c < 0 || r >= m || c >= n) return 0;
            if (dp[r][c][d][flag] != -1) return dp[r][c][d][flag];

            int ans = 1;
            int row = r + dir[d].first, col = c + dir[d].second;

            if (row >= 0 && col >= 0 && row < m && col < n) {
                if ((grid[r][c] == 0 && grid[row][col] == 2) ||
                    (grid[r][c] == 2 && grid[row][col] == 0)) {
                    ans = 1 + f(row, col, d, flag);
                }
            }

            if (flag) { // allow one clockwise turn
                int d1 = cw[d];
                int row1 = r + dir[d1].first, col1 = c + dir[d1].second;
                if (row1 >= 0 && col1 >= 0 && row1 < m && col1 < n) {
                    if ((grid[r][c] == 0 && grid[row1][col1] == 2) ||
                        (grid[r][c] == 2 && grid[row1][col1] == 0)) {
                        ans = max(ans, 1 + f(row1, col1, d1, 0));
                    }
                }
            }

            return dp[r][c][d][flag] = ans;
        };

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int r = i + dir[k].first, c = j + dir[k].second;
                        if (r >= 0 && c >= 0 && r < m && c < n && grid[r][c] == 2) {
                            ans = max(ans, 1 + f(r, c, k, 1)); // start with 1→2
                        }
                        else ans=max(ans,1);
                    }
                }
            }
        }

        return ans;
    }
};
