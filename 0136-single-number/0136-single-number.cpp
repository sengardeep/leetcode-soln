class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(begin(nums),end(nums),0,[](int a,int b){return a^b;});
    }
};