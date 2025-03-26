class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int start=image[sr][sc];
        vector<int> dir[]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(image[row][col]!=start) continue;
            image[row][col]=color;
            for(int i=0;i<4;i++)
            {
                int new_row=row+dir[i][0],new_col=col+dir[i][1];
                if(new_row<0 || new_row>=m || new_col<0 || new_col>=n || image[new_row][new_col]!=start) continue;
                q.push({new_row,new_col});
            }
        }
        return image;
    }
};