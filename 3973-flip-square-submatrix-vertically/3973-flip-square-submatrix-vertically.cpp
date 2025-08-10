class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        if (k <= 1) return grid;
        int m = grid.size(), n = grid[0].size();

        for (int i = x; i < x + k / 2; i++) {
            for (int j = y; j < y + k; j++) {
                swap(grid[i][j], grid[2*x + k - 1 - i][j]);
            }
        }

        return grid;
    }
};
