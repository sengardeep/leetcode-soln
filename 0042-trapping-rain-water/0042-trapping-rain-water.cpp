class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int mx=*max_element(begin(height),end(height));
        int l=-1,r=-1;
        for(int i=0;i<n;i++) {
            if(height[i]==mx){
                if(l==-1) l=i;
                r=i;
            }
        }
        //0 to r
        int ans=0;
        int i=0,j=1,curr=height[i];
        while(j<=r){
            if(height[i]<=height[j]){
                ans+=(j-i)*height[i];
                ans-=curr;
                i=j;
                curr=0;
            }
            curr+=height[j];
            j++;
        }
        //r to n-1
        i=n-1,j=n-2,curr=height[i];
        while(j>=r){
            if(height[i]<=height[j]){
                // cout<<i<<" "<<j<<endl;
                ans+=(i-j)*height[i];
                ans-=curr;
                i=j;
                // cout<<"ans: "<<ans<<endl;
                curr=0;
            }
            curr+=height[j];
            j--;
        }
        return ans;
    }
};