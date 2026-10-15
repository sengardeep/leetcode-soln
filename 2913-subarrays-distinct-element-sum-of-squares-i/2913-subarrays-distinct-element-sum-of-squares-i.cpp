class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                set<int> set;
                for(int k=i;k<=j;k++) set.insert(nums[k]);
                int m=set.size();
                ans += m*m;
            }
        }
        return ans;
    }
};