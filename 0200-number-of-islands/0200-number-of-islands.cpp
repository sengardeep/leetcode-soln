class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size(), n = grid[0].size();
        function<void(int, int)> dfs = [&](int r, int c) -> void {
            if (r < 0 || c < 0 || r > m - 1 || c > n - 1)
                return;
            if (grid[r][c] == '0')
                return;
            grid[r][c] = '0';
            for (int i = 0; i < 4; i++) {
                int row = r + dir[i].first, col = c + dir[i].second;
                dfs(row, col);
            }
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};