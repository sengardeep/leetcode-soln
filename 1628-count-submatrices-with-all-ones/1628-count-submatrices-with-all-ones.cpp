class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int ans=0;
        for(int start=0;start<m;start++){
            vector<int> count(n,1);
            for(int end=start;end<m;end++)
            {
                for(int col=0;col<n;col++){
                    count[col]=count[col]&mat[end][col];
                }

                ans += OnedArrayCount(count);
            }
        }
        return ans;
    }
private:
    int OnedArrayCount(vector<int>&arr){
        int ans=0,count=0;
        for(int x : arr)
        {
            if(x==0) count=0;
            else count++;
            ans += count;
        }
        return ans;
    }
};