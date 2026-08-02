class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=1;i<=n;i+=i){
            for(int j=0;j<i;j++){
                if(i+j<=n)
                ans[i+j]=ans[j]+1;
                else break;
            }
        }
        return ans;
    }
};