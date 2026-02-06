class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int ans=n-1;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            long long nxt=curr*1LL*k;
            int ub=upper_bound(begin(nums),end(nums),nxt)-begin(nums);
            ans=min(ans,n-ub+i);
        }
        return ans;
    }
};