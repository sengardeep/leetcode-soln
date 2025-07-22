class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> map(maxi+1,0);
        int start=0,end=0;
        int ans=0,sum=0;
        while(end<nums.size()){
            if(map[nums[end]]>0)
            {
                int num=nums[end];
                while(start<nums.size() && map[num]>0){
                    sum-=nums[start];
                    map[nums[start]]--;
                    start++;
                }
                // cout<<sum<<endl;
            }
            sum+=nums[end];
            map[nums[end]]++;
            ans=max(ans,sum);
            end++;
        }
        return ans;
    }
};