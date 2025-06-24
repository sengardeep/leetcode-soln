class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini1,mini2;
        mini1=mini2=INT_MAX;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mini1) mini1=nums[i];
            else if(nums[i]<mini2 && nums[i]>mini1) mini2=nums[i];

            if(nums[i]>mini2) return true;
        }
        return false;
    }
};