class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k) return 0;
        unordered_map<int,int> mp;
        for(auto x : nums) mp[x]++;
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++) 
        {
            if(mp[nums[i]]>0){
                int num=nums[i];
                for(int x=num;x<=num+k-1;x++) {
                    if(!mp.count(x) || mp[x]<1) return 0;
                    mp[x]--;
                }
            }
        }
        return 1;
    }
};