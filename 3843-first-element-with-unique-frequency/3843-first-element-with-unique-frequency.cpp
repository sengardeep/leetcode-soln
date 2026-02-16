class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int> mp,freq;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        for(auto [x,f] : mp) freq[f]++;
        for(int i=0;i<nums.size();i++){
            int f=mp[nums[i]];
            if(freq[f]==1) return nums[i];
        }
        return -1;
    }
};