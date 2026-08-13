class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(nums[i]!=-1){
            int nxt = nums[i];
            nums[i] = -1;
            i = nxt;
        }
        return i;
    }
};