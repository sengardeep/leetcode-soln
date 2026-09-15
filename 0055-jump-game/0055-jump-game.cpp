class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int i=n-2;
        while(i>=0){
            if(nums[i]==0){
                int j=i-1,num=2;
                while(j>=0){
                    if(num<=nums[j]) break;
                    j--;
                    num++;
                }
                if(j<0) return 0;
                i=j+1;
            }
            i--;
        }
        return 1;
    }
};