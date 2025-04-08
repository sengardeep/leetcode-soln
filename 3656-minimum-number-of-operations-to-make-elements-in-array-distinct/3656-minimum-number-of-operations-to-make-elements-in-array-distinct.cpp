class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int duplicates=0;
        unordered_map<int,int> mp;
        int ans=0;
        for(auto it : nums) mp[it]++;
        for(auto it : mp)
            {
                duplicates+=it.second-1;
            }
        while(duplicates>0)
            {
                if(nums.size()>3)
                {
                    nums.erase(nums.begin(),nums.begin()+3);
                }
                else
                {
                    nums.clear();
                }
                ans++;
                mp.clear();

                duplicates=0;
                for(auto it : nums) mp[it]++;
                for(auto it : mp) duplicates+=it.second-1;
            }
        return ans;
    }
};