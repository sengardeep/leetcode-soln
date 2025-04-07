class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O') DFS(board,i,0,m,n);
            if(board[i][n-1]=='O') DFS(board,i,n-1,m,n);
        }
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O') DFS(board,0,i,m,n);
            if(board[m-1][i]=='O') DFS(board,m-1,i,m,n);
        }

        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        if(board[i][j]=='O') board[i][j]='X';
        
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        if(board[i][j]=='#') board[i][j]='O';
    }
private:
    void DFS(vector<vector<char>>& board,int row,int col,int m,int n)
    {
        if(row<0 || row>=m || col<0 || col>=n || board[row][col]!='O') return;

        board[row][col]='#';
        vector<int> dir[]={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<4;i++)
        {
            int r=row+dir[i][0],c=col+dir[i][1];
            DFS(board,r,c,m,n);
        }
    }
};