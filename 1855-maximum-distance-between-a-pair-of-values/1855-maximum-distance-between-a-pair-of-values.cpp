class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        auto bs=[&](int x,int i){
            int start=i,end=nums2.size()-1;
            int ans=i;
            while(start<=end){
                int mid=(start+end)/2;
                if(nums2[mid]>=nums1[i]){
                    ans=mid;
                    start=mid+1;
                }else end=mid-1;
            }
            return ans;
        };
        for(int i=0;i<nums1.size();i++){
            int j=bs(nums1[i],i);
            ans=max(ans,j-i);
        }
        return ans;
    }
};