class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1e9));
        function<int(int,int)> helper=[&](int i,int j)->int{
            if(i==n || j==m) return 0;
            if(dp[i][j]!=-1e9) return dp[i][j];
            int ans=nums1[i]*nums2[j]+helper(i+1,j+1);
            ans=max({ans,helper(i,j+1),helper(i+1,j),helper(i+1,j+1)});
            return dp[i][j]=ans;
        };
        int ans=helper(0,0);
        if(!ans){
            int f=*min_element(begin(nums1),end(nums1)),s=*min_element(begin(nums2),end(nums2));
            if(nums1[0]<0) f=*max_element(begin(nums1),end(nums1));
            if(nums2[0]<0) s=*max_element(begin(nums2),end(nums2));
            return f*s;
        }
        return ans;
    }
};