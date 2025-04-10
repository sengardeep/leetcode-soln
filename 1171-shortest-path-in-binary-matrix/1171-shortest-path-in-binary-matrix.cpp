class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;
        if (n == 1 && grid[0][0] == 0)
            return 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<int> dir[] = {{0, 1}, {1, 0},   {-1, 0}, {0, -1},
                             {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        int d = 1;
        grid[0][0] = 1;
        while (!q.empty()) {
            int size = q.size();
            d++;
            while (size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int i = 0; i < 8; i++) {
                    int row = r + dir[i][0], col = c + dir[i][1];
                    if (row < 0 || col < 0 || row >= n || col >= n ||
                        grid[row][col] != 0)
                        continue;
                    grid[row][col] = d;
                    q.push({row, col});
                }
            }
        }
        return (grid[n - 1][n - 1] != 0) ? grid[n - 1][n - 1] : -1;
    }
};