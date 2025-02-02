class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;

        for(int i=0; i<n; i++){
            bool isValid=true;
            for(int j=i; j<i+n-1; j++){
                if(nums[j%n]>nums[(j+1)%n]){
                    isValid=false;
                }
            }
            if(isValid) return true;
        }
        return false;
    }
};