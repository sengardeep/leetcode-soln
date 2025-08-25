class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int i = 0, j = 0;
        vector<int> ans;
        bool flag = true;
        while ((int)ans.size() < m * n) {
            if (flag) {
                // i-1,j+1
                while (i >= 0 && j < n) {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                i++;
                j--;
            } else {
                // i+1,j-1
                while (i < m && j >= 0) {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                i--;
                j++;
            }
            // either right or down
            if (i == 0 || i == m - 1) {
                if (j != n - 1)
                    j++;
                else
                    i++;
            } else
                i++;
            flag = !flag;
        }
        return ans;
    }
};