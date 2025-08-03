class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int inc=0,dec=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]) 
            {
                inc++;
                while(i<n-1 && nums[i]<nums[i+1]) i++;
                i--;
            }
            else if(nums[i]>nums[i+1]){
                if(i==0) return false;
                dec++;
                while(i<n-1 && nums[i]>nums[i+1]) i++;
                i--;
            }
            else return false;
        }
        return (inc==2 && dec==1);
    }
};