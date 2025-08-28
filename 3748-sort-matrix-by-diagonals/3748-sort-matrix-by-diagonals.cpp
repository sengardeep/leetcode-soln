class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n,vector<int>(n));
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int r=i,c=0;
            while(r<n&&c<n){
                pq.push(grid[r][c]);
                r++;
                c++;
            }
            r=i,c=0;
            while(r<n&&c<n){
                ans[r][c]=pq.top();
                pq.pop();
                r++;
                c++;
            }
            if(i>0){
                r=0,c=i;
                while(r<n&&c<n){
                    pq.push(grid[r][c]);
                    r++;
                    c++;
                }
                r--;
                c--;
                while(r>=0&&c>=i){
                    ans[r][c]=pq.top();
                    pq.pop();
                    r--;
                    c--;
                }
            }
        }

        return ans;
    }
};