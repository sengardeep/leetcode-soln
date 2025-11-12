class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int g=0,flag=0;
        int ans=0;
        for(int i=0;i<n;i++) 
        {
            g=__gcd(nums[i],g);
            if(nums[i]>1)
            {
             flag=1;
             ans++;
            }
        }
        if(!flag) return 0;
        if(g!=1) return -1;
        if(ans!=n) return ans;
        ans--;
        int extra=n;
        for(int i=0;i<n-1;i++){
            g=nums[i];
            for(int j=i+1;j<n;j++){
                g=__gcd(nums[j],g);
                if(g==1) extra=min(extra,j-i);
            }
        }
        return ans+extra;
    }
};