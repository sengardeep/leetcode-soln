class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vector<pair<int,int>> nums;
        for(auto it : strs){
            int zero=0,one=0;
            for(int i=0;i<it.size();i++){
                zero+=it[i]=='0';
                one+=it[i]=='1';
            }
            nums.push_back({zero,one});
        }
        vector<vector<vector<int>>> dp(sz,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        function<int(int,int,int)> helper=[&](int index,int zero,int one)->int{
            if(index==sz) return 0;
            if(dp[index][zero][one]!=-1) return dp[index][zero][one];
            int skip=helper(index+1,zero,one);
            auto [c0,c1]=nums[index];
            int take=0;
            if(c1<=one&&c0<=zero) take=1+helper(index+1,zero-c0,one-c1);
            return dp[index][zero][one]=max(take,skip);
        };
        return helper(0,m,n);
    }
};