class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            if(i<=k){
                if(st.count(nums[i])) return 1;
                st.insert(nums[i]);
            }else{
                st.erase(st.find(nums[i-k-1]));
                if(st.count(nums[i])) return 1;
                st.insert(nums[i]);
            }
        }
        return 0;
    }
};