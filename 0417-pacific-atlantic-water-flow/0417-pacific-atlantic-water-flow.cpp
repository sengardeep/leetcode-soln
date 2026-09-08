class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        pair<int, int> dir[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<int>> ans;
        queue<pair<int, int>> pacific, atlantic;
        for (int i = 0; i < n; i++) {
            pacific.push({i, 0});
            atlantic.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            pacific.push({0,j});
            atlantic.push({n - 1, j});
        }
        set<pair<int, int>> vis;
        vector<pair<int, int>> ans1;
        while (!pacific.empty()) {
            auto [r, c] = pacific.front();
            pacific.pop();
            if (vis.count({r, c}))
                continue;
            vis.insert({r, c});
            ans1.push_back({r, c});
            for (auto [x, y] : dir) {
                int r1 = r + x, c1 = c + y;
                if (r1 < 0 || c1 < 0 || r1 >= n || c1 >= m)
                    continue;
                if (heights[r1][c1] >= heights[r][c])
                    pacific.push({r1, c1});
            }
        }
        vis.clear();
        vector<pair<int, int>> ans2;
        while (!atlantic.empty()) {
            auto [r, c] = atlantic.front();
            atlantic.pop();
            if (vis.count({r, c}))
                continue;
            ans2.push_back({r, c});
            vis.insert({r, c});
            for (auto [x, y] : dir) {
                int r1 = r + x, c1 = c + y;
                if (r1 < 0 || c1 < 0 || r1 >= n || c1 >= m)
                    continue;
                if (heights[r1][c1] >= heights[r][c])
                    atlantic.push({r1, c1});
            }
        }
        vector<vector<bool>> seen1(n, vector<bool>(m, false));
        for (auto [r, c] : ans1) {
            seen1[r][c] = true;
        }
        for (auto [r, c] : ans2) {
            if (seen1[r][c]) {
                ans.push_back({r, c});
            }
        }

        return ans;
    }
};