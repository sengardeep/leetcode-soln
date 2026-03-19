class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> v(n, {0, 0});
        int ans = 0;
        for (int i = 0; i < m; i++) {
            vector<pair<int,int>> temp=v;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X')
                    v[j].first += 1;
                else if (grid[i][j] == 'Y')
                    v[j].second += 1;
                if (j > 0) {
                    v[j].first += v[j - 1].first;
                    v[j].second += v[j - 1].second;
                    v[j].first -= temp[j-1].first;
                    v[j].second -= temp[j-1].second;
                }
                ans += ((v[j].first == v[j].second) && v[j].first);
                // cout<<v[j].first<<" "<<v[j].second<<"    ";
            }
            // cout<<endl;
        }
        return ans;
    }
};