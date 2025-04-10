class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // I'll go for binary search since it is kind of minimum of maximum
        int maxi = -1, mini = 1e6;
        int m = heights.size(), n = heights[0].size();
        for (auto it : heights) {
            maxi = max(maxi, *max_element(it.begin(), it.end()));
            mini = min(mini, *min_element(it.begin(), it.end()));
        }
        int start = 0, end = abs(maxi - mini),ans=0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            if (isPossible(heights, mid, 0, 0, visited))
            {
                ans=mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return ans;
    }

private:
    bool isPossible(vector<vector<int>>& heights, int d, int r, int c,
                    vector<vector<bool>>& visited) {
        int m = heights.size(), n = heights[0].size();
        if (r == m - 1 && c == n - 1)
            return true;
        visited[r][c] = true;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto& dir : dirs) {
            int ro = r + dir.first, co = c + dir.second;
            if (ro >= 0 && ro < m && co >= 0 && co < n && !visited[ro][co]) {
                int diff = abs(heights[ro][co] - heights[r][c]);
                if (diff <= d && isPossible(heights, d, ro, co, visited))
                    return true;
            }
        }
        return false;
    }
};