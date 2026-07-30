class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,x=-101;
        while(j<n){
            if(nums[j]==x) j++;
            else{
                x=nums[j];
                nums[i]=x;
                i++;
            }
        }
        return i;
    }
};