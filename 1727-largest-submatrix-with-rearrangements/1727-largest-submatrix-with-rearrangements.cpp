class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        for(int i=1;i<m;i++) for(int j=0;j<n;j++) if(matrix[i][j]) matrix[i][j]+=matrix[i-1][j];
        int ans=0;
        for(int i=0;i<m;i++) {
            vector<int> temp=matrix[i];
            sort(rbegin(temp),rend(temp));
            int mn=temp[0];
            for(int j=0;j<n;j++)
            {
                mn=min(mn,temp[j]);
                ans=max(ans,mn*(j+1));
            }
        }
        return ans;
    }
};