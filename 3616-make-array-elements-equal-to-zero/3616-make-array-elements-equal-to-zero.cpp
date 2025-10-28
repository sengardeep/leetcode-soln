class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];
        auto rangeSum=[&](int l,int r){
            if(r>n-1||l<0||l>r) return 0;
            int ans=pre[r];
            if(l>0) ans-=pre[l-1];
            return ans;
        };
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int left=rangeSum(0,i-1),right=rangeSum(i+1,n-1);
                if(left==right) ans+=2;
                else if(abs(left-right)==1) ans+=1;
            }
        }
        return ans;
    }
};