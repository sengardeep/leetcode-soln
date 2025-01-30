class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        string s(n, '.');
        for (int i = 0; i < n; i++)
            temp.push_back(s);
        solve(0, temp, ans, n);
        return ans;
    }

private:
    bool check(int row, int col, vector<string>& temp, int n) {
        int row1 = row, col1 = col;
        while (col1 >= 0) {
            if (temp[row1][col1] == 'Q')
                return false;
            col1--;
        }
        col1 = col;
        while (row1 >= 0 && col1 >= 0) {
            if (temp[row1][col1] == 'Q')
                return false;
            row1--;
            col1--;
        }
        row1 = row;
        col1 = col;
        while (row1 < n && col1 >= 0) {
            if (temp[row1][col1] == 'Q')
                return false;
            row1++;
            col1--;
        }
        return true;
    }
    void solve(int col, vector<string>& temp, vector<vector<string>>& ans,
               int n) {
        if (col == n) {
            ans.push_back(temp);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (check(row, col, temp, n)) {
                temp[row][col] = 'Q';
                solve(col + 1, temp, ans, n);
                temp[row][col] = '.';
            }
        }
    }
};