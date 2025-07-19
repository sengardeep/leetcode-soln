class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        vector<int> dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    // BFS
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    long long sum = grid[i][j];
                    grid[i][j]=0;
                    while (!q.empty()) {
                        int r = q.front().first, c = q.front().second;
                        q.pop();
                        for (auto it : dir) {
                            int row = r + it[0], col = c + it[1];
                            if (row >= 0 && row < m && col >= 0 && col < n &&
                                grid[row][col] != 0) {
                                q.push({row, col});
                                sum+=grid[row][col];
                                grid[row][col]=0;
                            }
                        }
                    }
                    if (sum % k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};