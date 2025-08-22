class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int one1 = n, one2 = -1, first = -1,last=-1;
        for (int i = 0; i < n; i++) {
            int one3=-1,one4=-1;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if(first==-1)
                    first = i;
                    last=i;
                    if (one3 == -1)
                        one3 = j;
                    one4 = j;
                }
            }
            if(one3 != -1) one1=min(one1,one3);
            if(one4 != -1) one2=max(one2,one4);
        }
        int width = one2-one1+1;
        // cout<<width<<" "<<one2<<" "<<one1;
        int height = (last - first + 1);
        return width * height;
    }
};