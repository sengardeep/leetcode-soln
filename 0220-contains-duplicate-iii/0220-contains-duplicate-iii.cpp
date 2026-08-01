class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            if(i>indexDiff){
                st.erase(st.find(nums[i-indexDiff-1]));
            }
            int num=nums[i];
            if(st.count(num)) return 1;
            auto ub=st.upper_bound(num);
            if(ub!=st.begin()){
                --ub;
                int prev=*ub;
                if(abs(num-prev)<=valueDiff) return 1;
                ++ub;
            }
            if(ub!=st.end()){
                int nxt=*ub;
                if(abs(num-nxt)<=valueDiff) return 1;
            }
            st.insert(nums[i]);
        }
        return 0;
    }
};