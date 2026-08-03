class Solution {
public:
    int shipWithinDays(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),end(nums),0);
        int start=0,end=sum,ans=0;
        auto check = [&](int x){
            int count=0,curr=0;
            for(int i=0;i<n;i++){
                if(curr+nums[i]>x) {
                    count++;
                    curr=0;
                }
                if(nums[i]>x) return false;
                curr+=nums[i];
            }
            if(curr) count++;
            return count<=k;
        };
        while(start<=end){
            int mid=end+(start-end)/2;
            if(check(mid)){
                ans=mid;
                end=mid-1;
            }else start=mid+1;
        }
        return ans;
    }
};