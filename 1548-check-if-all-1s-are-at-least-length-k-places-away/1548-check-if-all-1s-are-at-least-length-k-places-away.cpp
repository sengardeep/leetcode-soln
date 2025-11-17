class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int zero=-1e9;
        for(int x : nums){
            if(x==0){
                zero++;
            }else{
                if(zero>=0 && zero<k) return false;
                zero=0;
            }
        }
        return true;
    }
};