class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int start = 0, end = row * col - 1;
        vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        while (start <= end) {
            int mid = (start + end) / 2;
            bool flag = false;
            {
                vector<vector<int>> mat(row, vector<int>(col, 0));
                vector<vector<int>> vis(row, vector<int>(col, 0));
                for (int i = 0; i <= mid; i++)
                    mat[cells[i][0] - 1][cells[i][1] - 1] = 1;
                function<int(int, int)> dfs = [&](int r, int c) -> int {
                    if (r < 0 || c < 0 || r >= row || c >= col)
                        return 0;
                    if (vis[r][c] == 1)
                        return 0;
                    if (mat[r][c] == 1)
                        return 0;
                    if (r == row - 1)
                        return 1;
                    vis[r][c] = 1;
                    int ans = 0;
                    for (int i = 0; i < 4; i++) {
                        int r1 = r + d[i].first, c1 = c + d[i].second;
                        ans = max(ans, dfs(r1, c1));
                    }
                    return ans;
                };
                for (int i = 0; i < col; i++) {
                    if (dfs(0, i)) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start;
    }
};