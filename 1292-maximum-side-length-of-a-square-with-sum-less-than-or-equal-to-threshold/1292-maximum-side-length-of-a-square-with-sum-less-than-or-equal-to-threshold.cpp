class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> pre(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pre[i][j]=mat[i][j];
                if(i) pre[i][j]+=pre[i-1][j];
                if(j) pre[i][j]+=pre[i][j-1];
                if(i && j) pre[i][j]-=pre[i-1][j-1];
            }
        }
        auto rangeSum=[&](int r1,int c1,int r2,int c2){
            int ans=pre[r2][c2];
            if(r1) ans-=pre[r1-1][c2];
            if(c1) ans-=pre[r2][c1-1];
            if(r1 && c1) ans+=pre[r1-1][c1-1];
            return ans;
        };
        auto check=[&](int k){
            for(int i=0;i+k-1<m;i++){
                for(int j=0;j+k-1<n;j++){
                    int sum=rangeSum(i,j,i+k-1,j+k-1);
                    if(sum<=threshold) return 1;
                }
            }
            return 0;
        };
        int start=1,end=min(m,n),ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(check(mid)) 
            {
            start=mid+1;
            ans=mid;
            }
            else end=mid-1;
        }
        return ans;
    }
};