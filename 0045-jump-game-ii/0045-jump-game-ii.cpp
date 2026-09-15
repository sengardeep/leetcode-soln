class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,n+1);
        int mx=0;
        ans[0]=0;
        for(int i=0;i<n;i++){
            for(int j=mx+1;j<i+nums[i]+1 && j<n;j++) ans[j]=ans[i]+1;
            mx=max(mx,i+nums[i]);
        }
        return ans[n-1];
    }
};